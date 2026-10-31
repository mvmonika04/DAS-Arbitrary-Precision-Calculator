#include"calc.h"

int validation(int argc,char *argv[])
{   
     int i;

     /* Validate CLA command*/
     if(argc != 4)
     {
        printf("\n================================================================\n");
        printf("           Arbitrary precision calculator                           ");
        printf("\n================================================================\n");
        printf(" USAGE : \n  ./calc.out <operand1> <operator> <operand2>\n\n");
        printf(" SUPPORTED OPERATIONS:\n");
        printf(" + Addtion \n");
        printf(" - Subtraction \n");
        printf(" x Multiplication\n");
        printf(" / Division \n\n");
        printf("================================================================\n");

        return FAILURE;
     }

     /*validate first operand*/
     i=0;

     if(argv[1][i]=='+'||argv[1][i]=='-')
         i++;
     if(argv[1][i]=='\0')
     {
        printf("ERROR: Invalid first operand\n");
        return FAILURE;
     }   
     for(;argv[1][i] != '\0';i++)
     {
        if(!isdigit(argv[1][i]))
        {
            printf("ERROR: Invalid first operand\n");
            return FAILURE;
        }
     } 
     /*Validate operators*/
     if(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != 'X' && argv[2][0] != '/')
     {
        printf("ERROR : Invalid operator '%s'\n",argv[2]);
        return FAILURE;
     }

     /*validate second operand*/
      i=0;

     if(argv[3][i]=='+'||argv[3][i]=='-')
         i++;
     if(argv[3][i]=='\0')
     {
        printf("ERROR: Invalid first operand\n");
        return FAILURE;
     }   
     for(;argv[3][i] != '\0';i++)
     {
        if(!isdigit(argv[3][i]))
        {
            printf("ERROR: Invalid first operand\n");
            return FAILURE;
        }
     } 

     return SUCCESS;
}
