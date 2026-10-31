#include "calc.h"


int main(int argc, char *argv[])
{  
    /*Initializuing Double linked list head and tail pointers to NULL*/
    L_list *head1=NULL;
    L_list *tail1=NULL;

    L_list *head2=NULL;
    L_list *tail2=NULL;

    L_list *headR=NULL;
    L_list *tailR=NULL;
    
    /*CLA validation*/
    if(validation(argc, argv) != 1)

        return FAILURE;
    /*get operand 1 and operand 2 - or + sign*/
    int sign1=get_sign(argv[1]);
    int sign2=get_sign(argv[3]);

    /*Converting operand 1 string into integer */
    if(string_to_integer(&head1,&tail1,argv,1)==-1)
    {
           return FAILURE;
    }
    /*removing zeros*/
    remove_leading_zeros(&head1, &tail1);
    
    /*Converting operand 2 string into integer*/
    if(string_to_integer(&head2,&tail2,argv,3)==-1)
    {
           return FAILURE;
    }
    /*removing zeros*/
    remove_leading_zeros(&head2, &tail2);
    

    int operation=argv[2][0];
    
    /*Switching operation based on user input */
    switch(operation)
    {   
        /*Addition operation*/
        case '+':
        {   
            if(sign1==1 && sign2 == 1)
            {   /* +A + +B = A + B*/
                addition(tail1,tail2,&headR, &tailR);
            }
            else if(sign1 == 1 && sign2 == -1)
            {   /* +A + -B = A - B*/
                  if(compare_list(head1,head2)==SUCCESS)
                  {
                     subtraction(tail1, tail2, &headR,&tailR);
                  }   

                  else   
                  {
                      subtraction(tail2,tail1, &headR, &tailR);
                      if(!is_zero(headR))
                          printf("-");
                  }

            }
            else if(sign1==-1 && sign2 == 1)
            {   
                /* -A + B = B - A */
                 if(compare_list(head1,head2)==SUCCESS)
                  {
                     subtraction(tail1, tail2, &headR,&tailR);
                      if(!is_zero(headR))
                          printf("-");
                  }   

                  else   
                  {
                      subtraction(tail2,tail1, &headR, &tailR);
                     
                  }

            }
            else
            {
                /* -A + -B = -(A + B)*/
                addition(tail2,tail1, &headR, &tailR);
                if(!is_zero(headR))
                    printf("-");
            }
            break;
        }
        /*Subtraction operation*/
        case '-':
        {
            if(sign1 ==1 && sign2 == 1)
            {
                /* +A - +B = A - B*/
                if(compare_list(head1,head2)==1)
                {
                    subtraction(tail2,tail1, &headR, &tailR);
                }
                else
                {
                    subtraction(tail2,tail1, &headR, &tailR);
                    if(!is_zero(headR))
                        printf("-");
                }
            }
            else if(sign1 == 1 &&  sign2== -1)
            {
                /* +A - -B = A + B*/
                  addition(tail2,tail1, &headR, &tailR);
            }
            else if(sign1 == -1 && sign2 == 1)
            {
                /* +A - -B = -(A + B)*/
                 addition(tail2,tail1, &headR, &tailR);
                 if(tail1->data >= tail2->data)
                 {
                   if(!is_zero(headR))
                        printf("-");

                 }
            }     
            else
            {
                /* -A - -B = B - A*/
                if(compare_list(head1,head2)==1)
                {
                    subtraction(tail2,tail1, &headR, &tailR);
                    if(!is_zero(headR))
                        printf("-");
                }
                else
                {
                    subtraction(tail2,tail1, &headR, &tailR);
                    
                }
            }
            break;
        }
      /*Multiplication Operation*/
        case 'x':
        case 'X':
        {  /* A x B = AB*/
           multiplication(head1, tail1, head2,tail2, &headR, &tailR);
           /* -A X B = -AB or A X -B =  -AB*/
           if(sign1 != sign2 && !is_zero(headR))
              printf("-");
            break;
        }
      
        /*Division Operation*/
        case '/':
      {
         
           if(division(head1, tail1, head2,tail2, &headR, &tailR)==FAILURE)
            {
                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);

                return FAILURE;
            }

            /*  -A / B  = -(ans) or A / -B = (ans)*/
            if(sign1 != sign2 && !is_zero(headR))
            printf("-");

            break;
      } 
      /*Operation for Invalid operator*/
        default:
        {
                printf("!Invalid Operator\n");
               
                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);

                return FAILURE;
        }        

    }
    /*Display result*/
    L_list *temp=headR;
    
    printf("Result  : ");
    while(temp)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}    
