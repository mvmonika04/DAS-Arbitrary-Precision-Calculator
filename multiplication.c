#include"calc.h"
int multiplication(L_list *head1, L_list *tail1, L_list *head2,L_list *tail2,L_list **headR,L_list **tailR)
{   
    /*defination and declaration of identifiers*/
    int result;
    int count=0;
    /*Suppress unused parameter warnings */
    (void)head1;
    (void)head2;

    /*Temporary pointer and result list pointer initialization*/
    L_list *temp;
    
    
    L_list *r_head1=NULL;
    L_list *r_tail1=NULL;

    L_list  *r_head2=NULL;
    L_list  *r_tail2=NULL;
    
    /*intializing Result list head and tail pointer to  Null*/
    *headR=NULL;
    *tailR=NULL;
    
    /*traversing list 2 upto null*/
    while(tail2 != NULL)
    {    
         int carry=0;
         temp=tail1;
         /*traversing list 1 upto null*/
         while(temp != NULL)
         {  
            /*list 1 and list 2 each digit multiplication + carry*/
            result=(temp->data * tail2->data)+carry;
            
            /*condition for cecking carry present or not*/
            if(result>9)
            {
                carry=result/10;
                result=result%10;
            }

            /*if not present intialize carry to zero*/
            else
            {
                carry=0;
            }
            
            /*inseting result digit into result list*/
            if(insert_at_first(&r_head2,&r_tail2,result)==FAILURE)
                return FAILURE;

            temp=temp->prev;    
         }
         /*Insert remaining carry*/
         if(carry != 0)
         {
            if(insert_at_first(&r_head2,&r_tail2,carry)==FAILURE)
                return FAILURE;
         }
         /*Add zeros accoriding to count */
         for(int i=0;i<count;i++)
         {
            if(insert_at_last(&r_head2,&r_tail2,0)==FAILURE)
             return FAILURE;
         }
         /*Partial result*/
         if(count == 0)
         {
              r_head1=r_head2;
              r_tail1=r_tail2;
         }
         else
         {  
            /*add current result list and handle any failure*/
            if(addition(r_tail1, r_tail2,headR,tailR)==FAILURE)
               return FAILURE;
             
               /*free the temporaray lists*/
            delete_list(&r_head1,&r_tail1);
            delete_list(&r_head2, &r_tail2);
            
            /*update first result list after combining them*/
            r_head1=*headR;
            r_tail1=*tailR;

         }

         /*Reset the second result list pointer*/
         r_head2=NULL;
         r_tail2=NULL;

         tail2=tail2->prev;
         count++;
    }

    /*Updatinf result head and tail pointer*/
    *headR=r_head1;
    *tailR=r_tail1;
    remove_leading_zeros(headR,tailR);

    return SUCCESS;
}
