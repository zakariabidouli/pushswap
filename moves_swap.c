#include "push_swap.h"

void swap_first(t_stack **head_ref)
{
    t_stack *temp;
    int     num_temp;

    temp = *head_ref;
    while(temp && temp->position < 2)
    {
        if(temp->position == 0)
        {
            // printf("#################### :%d\n", temp->next->num);
            num_temp = temp->num;
            temp->num = temp->next->num;
        }
        else if(temp->position == 1)
            temp->num = num_temp;
        temp = temp->next;
    }
}

void    s_a(t_stack  **head_ref)
{
    swap_first(head_ref);
    printf("s_a\n");
}

void    s_b(t_stack  **head_ref)
{
    swap_first(head_ref);
    printf("s_b\n");
}

void    s_s(t_stack  **head_ref_a, t_stack  **head_ref_b)
{
    swap_first(head_ref_a);
    swap_first(head_ref_b);
    printf("s_s\n");
}
