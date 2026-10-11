#include "main.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *headR2 = NULL, *tailR2 = NULL;
    node *head_AR = NULL, *tail_AR = NULL;

    
    node *temp1 = tail1, *temp2 = tail2;
    int count = 0; 
    int carray = 0;
 
    
    while(temp2 != NULL)
    {
        int num = temp2->data;
        temp1 = tail1;

        carray = 0;
        
        if(count != 0)
        {
            addition(*tailR, tailR2, &head_AR, &tail_AR);
            delete_list(headR, tailR);
            delete_list(&headR2, &tailR2);

            *headR = head_AR;
            *tailR = tail_AR;

        
            head_AR = NULL;
            tail_AR = NULL;
        }

        
        int pad = count;
        while(pad != 0)
        {
        
            insert_first(&headR2, &tailR2, 0);
            pad--;
        }

        while(temp1 != NULL)
        {
            int result = carray + temp1->data * num;
            if(result > 9)
            {
                carray = result / 10;
                result %= 10;
            }
            else
            {
                carray = 0;
            }

            if(count == 0)
            {
                insert_first(headR, tailR, result);
            }
            else
            {        
                insert_first(&headR2, &tailR2, result);
            }

            temp1 = temp1->prev;
        }

        
        if(carray > 0)
        {
            if(count == 0)
                insert_first(headR, tailR, carray);
            else
                insert_first(&headR2, &tailR2, carray);
            carray = 0;
        }
        count++;
        temp2 = temp2->prev;
    }


    
    if(*headR != NULL && headR2 != NULL)
    {
        addition(*tailR, tailR2, &head_AR, &tail_AR);
        delete_list(headR, tailR);
        delete_list(&headR2, &tailR2);

        *headR = head_AR;
        *tailR = tail_AR;
    }
}