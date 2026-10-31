#include"calc.h"

int addition(L_list *tail1, L_list *tail2, L_list **headR ,L_list **tailR)
{   
   /*declaration and defination of carry and result variable*/
    int carry=0;
    int result;
    
    /*intializing result head ,tail value as NULL*/
    *headR=NULL;
    *tailR=NULL;
    
    /*tarverse till last Node*/
    while(tail1 != NULL || tail2 != NULL)
    {
           if(tail1 != NULL && tail2 != NULL)
           {
             result= tail1->data + tail2->data + carry;
             tail1=tail1->prev;
             tail2=tail2->prev;
           }

           /*only list one has remaining nodes*/
           else if(tail1 != NULL && tail2 == NULL)
           {
              result=tail1->data + carry;
              tail1=tail1->prev;
           }
           /*only list two has remaining nodes*/
           else if(tail1 == NULL && tail2 != NULL)
           {
              result=tail2->data+carry;
              tail2=tail2->prev;
           }

           /* common carry and result calculation*/
           if(result>9)
           {
              carry=result/10;
              result=result%10;
           }
           else
           {
              carry=0;
           }
           if(insert_at_first(headR,tailR,result)==FAILURE)
              return FAILURE;
    }
    /*condition for carry value*/
    if(carry != 0)
    {
        if(insert_at_first(headR,tailR,result)==FAILURE)
              return FAILURE;
    }
    remove_leading_zeros(headR,tailR);
    return SUCCESS;
}