#ifndef  CALC_H
#define CALC_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define FAILURE -1
#define SUCCESS 1

typedef int data_t;
typedef struct Node
{
    data_t data;
    struct Node* next;
    struct Node* prev;
    
    
}L_list;

/*Validate Command line arguments*/
int validation(int argc,char *argv[]);

/*Converting numeric string into a linked list digit*/
int string_to_integer(L_list **head,L_list **tail,char *agrv[], int index);

/*Removing leading zeros from a linked list*/
int remove_leading_zeros(L_list **head,L_list **tail);

/*Determine the sign of the number*/
int get_sign(char *sign_ch);

/*Compare to linked list numbers*/
int compare_list(L_list *head1,L_list *head2);

/*check whether the linked list number is zero*/
int is_zero(L_list *head);

/*insert a digit at the end of the list*/
int insert_at_last(L_list **head, L_list **tail, int  data);

/*insert a digit at the beginning of the result list with carry*/
int insert_at_first(L_list **headR,L_list **tailR, int carry);

/*Perform addition of two linked list*/
int addition(L_list *tail1, L_list *tail2, L_list **headR ,L_list **tailR);

/*Perform subtraction of two linked list*/
int subtraction(L_list  *tail2,L_list *tail1, L_list **headR, L_list **tailR);

/*Perform multiplication of two linked list*/
int multiplication(L_list *head1, L_list *tail1, L_list *head2,L_list *tail2,L_list **headR,L_list **tailR);

/*Perform division of two linked list*/
int division(L_list *head1, L_list *tail1, L_list *head2,L_list *tail2, L_list **headR, L_list **tailR);


/*free all nodes in the linked list*/
void delete_list(L_list **head, L_list **tail);
#endif