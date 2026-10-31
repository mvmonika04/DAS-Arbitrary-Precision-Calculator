#include"calc.h"

int subtraction(L_list  *tail2,L_list *tail1, L_list **headR, L_list **tailR)
{    
      /*declaration and defination of identifiers*/
      int borrow=0;
      int result;
      int data1;
      
      /*intializing result head and tail*/
      *headR = NULL;
      *tailR = NULL;
      
      /*traversing upto last node*/
      while(tail1 != NULL || tail2 != NULL)
      {    
         /*case 1 : Both list have nodes*/
           if(tail1 != NULL && tail2 != NULL)
           {
              data1= tail1->data - borrow;
              if(data1>=tail2->data)
              {
                 result=data1-tail2->data;
                 borrow=0;
              }
              else
              {
                  result=data1+10-tail2->data;
                  borrow=1;
              }
              tail1=tail1->prev;
              tail2=tail2->prev;
           }
           /*case 2: Only first list has remaining nodes*/
           else if(tail1 != NULL)
           {
               data1 =tail1->data-borrow;

               if(data1<0)
               {
                  result=data1+10;
                  borrow=1;
               }
               else
               {
                  result=data1;
                  borrow=0;
               }
               tail1=tail1->prev;
           }
           /*inserting result into result list*/
           if(insert_at_first(headR,tailR,result)==FAILURE)
               return FAILURE;
      }
      remove_leading_zeros(headR,tailR);
      return SUCCESS;
}