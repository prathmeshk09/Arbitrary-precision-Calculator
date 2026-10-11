#include "main.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry = 0;   
 
    
    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        int digit1 = 0, digit2 = 0;   

        if (tail1 != NULL)  
        {
            digit1 = tail1->data;  
            tail1 = tail1->prev;   
        }

        if (tail2 != NULL)  
        {
            digit2 = tail2->data;  
            tail2 = tail2->prev;   
        }

        int sum = digit1 + digit2 + carry;  

        int result_digit = sum % 10;  
        carry = sum / 10;             

        // create new node for result digit
        node *new = malloc(sizeof(node));

        new->data = result_digit;  
        new->prev = NULL;          
        new->next = NULL;          

        
        if (*headR == NULL)
        {
            *headR = *tailR = new;  
        }
        else
        {
            new->next = *headR;     
            (*headR)->prev = new;   
            *headR = new;           
        }
    }
}