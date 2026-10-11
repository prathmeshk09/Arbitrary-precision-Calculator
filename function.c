//FUNCTION DEFINE

#include "main.h"


int cla_validation(int argc, char *argv[])
{ 
    
    if(argc != 4)
    { 
        printf("Invalid arguments\n");
        printf("INFO : Addition : ./a.out 124 + 12\n");
        printf("INFO : Substraction : ./a.out 123 - 111\n");
        printf("INFO : Multiplication : ./a.out 123 x 2\n");
        printf("INFO : Division : ./a.out 12 / 2\n");
        return FAILURE;
    } 

    
    int i=0;
    if(argv[1][0] == '-')
    {
        i=1;
    }

    
    for(; argv[1][i] != '\0'; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("PLEASE ENTER DIGITS ONLY\n");
            printf("INFO : ./a.out -12 + -12\n");
            return FAILURE;
        }
    }

    
    i=0;
    if(argv[3][0] == '-')
    {
        i=1;
    }

    
    for(; argv[3][i] != '\0'; i++)
    {
        if(!isdigit(argv[3][i]))
        {
            printf("PLEASE ENTER DIGITS ONLY\n");
            printf("INFO : ./a.out -12 + -12\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

//creating list
void create_list(char *opr, node **head, node **tail)
{
    
    for(int i=0; opr[i] != '\0'; i++)
    {
       
        if(!insert_last(head, tail, opr[i] - '0'))
        {
            printf("Operation failed\n");
            return;
        }
    }
}

//insert node at first
int insert_first(node **head, node **tail, int data)
{
    
    node *new = malloc(sizeof(node));

    if(!new)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;

    //if list is empty
    if(*head == NULL)
    {
        new->next = NULL;
        *head = new;
        *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}

//insert node at last
int insert_last(node **head, node **tail, int data)
{
    
    node *new = malloc(sizeof(node));

    if(!new)
    {
        return FAILURE;
    }

    new->data = data;
    new->next = NULL;

    //if list is empty
    if(*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        *tail = new;
    }
    else
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}

//delete entire list
int delete_list(node **head, node **tail)
{
    
    if(*head == NULL)
    {
        return FAILURE;
    }

    node *temp = *head;

    
    while(temp != NULL)
    {
        
        node *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}

//print linked list
void print_list(node *head)
{
    
    if(head == NULL)
    {
        printf("INFO: List is empty\n");
    }
    else
    {
        while(head)
        {
            
            printf("%d", head->data);

            
            head = head->next;
        }
        printf("\n");
    }
}


void remove_pre_zeros(node **head)
{
   
    if(*head == NULL)
    {
        return;
    }

    
    node *temp = *head;

    
    while(temp->data == 0 && temp->next != NULL)
    {
        
        node *del = temp;
        temp = temp->next;

        free(del);
        temp->prev = NULL;
    }

    *head = temp;
}


int list_len(node *head)
{
    int count = 0;

    
    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

 
int compare_list(node *head1, node *head2) 
{ 
    int len1 = list_len(head1); 
    int len2 = list_len(head2); 
    
     
    if(len1 > len2) 
    { 
        return 1; 
    } 
    else if(len1 < len2) 
    { 
        return -1; 
    } 
    
    
    while(head1 && head2) 
    { 
        if(head1->data > head2->data) 
        { 
            return 1; 
        } 
        else if(head1->data < head2->data) 
        { 
            return -1; 
        } 
        
        head1 = head1->next; 
        head2 = head2->next; 
    } 
    return SAME; 
}