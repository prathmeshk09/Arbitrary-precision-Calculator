//DIVISION FUNCTION

#include "main.h"


node *get_tail(node *head)
{
    
    if (head == NULL)
        return NULL;

    
    while (head->next != NULL)
        head = head->next;
 
    return head;
}

void division(node *head1, node *head2, node **headR, node **tailR)
{
    
    node *temp_head = NULL;             
    node *temp_tail = NULL;

    node *cur = head1;
    node *tail2 = get_tail(head2);

    *headR = NULL;
    *tailR = NULL;

    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero is not possible\n"); 
        return;
    }

    
    while (cur != NULL)
    {
        
        insert_last(&temp_head, &temp_tail, cur->data);   

        
        remove_pre_zeros(&temp_head);

        
        if (compare_list(temp_head, head2) < 0)
        {
            insert_last(headR, tailR, 0);
        }
        else
        {
            int count = 0;

            
            while (compare_list(temp_head, head2) >= 0)
            {
                node *res_head = NULL;
                node *res_tail = NULL;

               
                subtraction(temp_head, temp_tail, head2, tail2, &res_head, &res_tail);

                
                delete_list(&temp_head, &temp_tail);      

                
                temp_head = res_head;                     
                temp_tail = res_tail;

                count++;
            }

            
            insert_last(headR, tailR, count);             
        }

        cur = cur->next;
    }

    remove_pre_zeros(headR);

    delete_list(&temp_head, &temp_tail);
}