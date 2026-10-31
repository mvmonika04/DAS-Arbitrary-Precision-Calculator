#include"calc.h"

int insert_at_last(L_list **head, L_list **tail, int  data)
{  
    /*Creating new Node*/
    L_list *new=malloc(sizeof(L_list));

    /*Validate */
    if(new==NULL)
       return FAILURE;
    /*Update*/  
    new->data=data;
    new->next=NULL;
    new->prev=*tail;

    /*inserting first node*/
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
   
    /*inseting node at  last*/
   else
   {
     (*tail)->next=new;
     *tail=new;
   }
    return SUCCESS;
}
int insert_at_first(L_list **headR,L_list **tailR, int carry)
{     
    /*Creating new node*/
      L_list *new=malloc(sizeof(L_list));

      /*Validate*/
      if(new== NULL)
          return FAILURE;

      /*update*/    
      new->data=carry;
      new->next=*headR;
      new->prev=NULL;
      
      /*inserting first node*/
      if(*headR == NULL)
      {
         *headR=new;
         *tailR=new;
         return SUCCESS;
      }

      /*Inserting node at first*/
      (*headR)->prev=new;
      *headR=new;

      return SUCCESS;

}
int string_to_integer(L_list **head,L_list **tail,char *agrv[], int index)
{
    int i=0;

    /*updating value i=1 if operand 1 or 2 have + or - */
    if(agrv[index][0] == '+'||agrv[index][0]=='-')
       i++;
    for(;agrv[index][i] != '\0';i++)
    {
           if(insert_at_last(head,tail,agrv[index][i]-'0')== FAILURE)
               return FAILURE;
    }
       return SUCCESS;
}
int remove_leading_zeros(L_list **head,L_list **tail)
{    
    L_list *temp;

    /*removing leading zeros*/
    while(*head && (*head)->data == 0 && (*head)->next )
    {
             temp=*head;
             *head=(*head)->next;
             (*head)->prev=NULL;
             free(temp);

    }
    /*if head iS NULL updating tail also NUll*/
    if(*head==NULL)
       *tail=NULL;
    return SUCCESS;
}
int get_sign(char *sign_ch)
{   
    /*checking operand sign*/
    if(sign_ch[0] == '-')
       return -1;
    return 1;       
}
int is_zero(L_list *head)
{   
    /*checking operand contain 0 or not*/
    if(head != NULL && head->data==0 && head->next == NULL)
        return 1;
    return 0;    
}
int compare_list(L_list *head1,L_list *head2)
{    
    int len1=0;
    int len2=0;

    L_list *temp1= head1;
    L_list *temp2= head2;
    
    /*find operand1 length*/
     while(temp1!= NULL)
     {
         len1++;
         temp1=temp1->next;
     }
    
     /*find operand 2 length*/
     while(temp2!= NULL)
     {
         len2++;
         temp2=temp2->next;
     }
      
     /*condition for operand 1 greater then operand 2*/
     if(len1>len2)
         return 1;
     
     /*condition for operand 2 greater then operand 1*/
     if(len1<len2)
         return 0;
         
     temp1=head1;
     temp2=head2;
     while(temp1 != NULL)
     {
        if(temp1->data > temp2->data)
            return 1;
        if(temp1->data < temp2->data)
            return 0;
            
        temp1=temp1->next;
        temp2=temp2->next;    
     }    
     return 1;
}
void delete_list(L_list **head, L_list **tail)
{
    L_list *temp;
    /*deleting list*/
    while (*head)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    *tail=NULL;
    
}