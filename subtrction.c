#include "main.h"

void subtraction(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR)
{
    int borrow = 0;

    *headR = NULL;
    *tailR = NULL;

    while(tail1 != NULL || tail2 != NULL)
    {
        int digit1 = (tail1) ? tail1->data : 0;
        int digit2 = (tail2) ? tail2->data : 0;

        int diff = digit1 - digit2 - borrow;
        if(diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_first(headR, tailR, diff);

        if(tail1)
            tail1 = tail1->prev;
        
        if(tail2)
            tail2 = tail2->prev;
    }
    remove_pre_zeros(headR);
} 
