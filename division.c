#include "calc.h"
int division(L_list *head1, L_list *tail1, L_list *head2,L_list *tail2, L_list **headR, L_list **tailR)
{
    /*Suppress unused parameter warnings*/
    (void)tail1;

    /*Initialize the main result list pointer*/
    L_list *main_head=NULL;
    L_list *main_tail=NULL;
    
    /*Initialize the sub-result list pointer*/
    L_list *sub_head=NULL;
    L_list *sub_tail=NULL;
    
    /*point temp to the beginning pf the first input*/
    L_list *temp=head1;

    /*Initialize the output list head and tail pointers*/
     *headR=NULL;
     *tailR=NULL;

    int count;

    //Division by zero
    if(head2->data == 0 && head2->next == NULL)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }
    
    /*traversing operand 1 upto null*/
    while (temp != NULL)
    {   
        /*inserting result digit at last node*/
        if(insert_at_last(&main_head, &main_tail,temp->data)==FAILURE)
           return FAILURE;

         remove_leading_zeros(&main_head,&main_tail);
         
         /*intialize count value to zero*/
         count=0;
         
         /*compare the main result with operand 2*/
         while(compare_list(main_head,head2)==1)
         {
            /*subtracting operand 2 from the main result*/
            if(subtraction(tail2 ,main_tail, &sub_head,&sub_tail)==FAILURE)
            { 
               /*free the temporary reault list*/
                delete_list(&main_head,&main_tail);
                return FAILURE;
            }  
           /*updating count value*/
            count++;

            delete_list(&main_head,&main_tail);
           /*reset the main head and tail */
            main_head=sub_head;
            main_tail=sub_tail;
           
            /*reset sub head and tail to null*/
            sub_head=NULL;
            sub_tail=NULL;

            remove_leading_zeros(&main_head,&main_tail);
         }
         /*inserting result at last*/
         if(insert_at_last(headR,tailR,count)==FAILURE)
         {
            delete_list(&main_head,&main_tail);
            return FAILURE;
         }
         /*updating temp to next point*/
         temp=temp->next;
    }
   
    /*removing zeros*/
    remove_leading_zeros(headR,tailR);

    //delete_list(&main_head,&main_tail);
    
     return SUCCESS;
}