#include "push_swap.h"

void    p_b(t_stack **head_ref_a,t_stack **head_ref_b)
{
    t_stack *temp_b;
    t_stack *temp_a;
    int     temp;

    temp_b = *head_ref_b;
    temp_a = *head_ref_a;
    if(temp_b)
    {
        temp = temp_a->num;
        push_front(head_ref_b, temp);
        deleteNode(head_ref_a, temp_a);
        while(temp_a)
        {   
            temp_a->position += 1;
            temp_a = temp_a->next;
        }
    }
}

void p_a(t_stack **head_ref_a, t_stack  **head_ref_b)
{
    t_stack *temp_b;
    t_stack *temp_a;
    int     temp;

    temp_a = *head_ref_a;
    temp_b = *head_ref_b;
    if(temp_a)
    {
        temp = temp_b->num;
        push_front(head_ref_a, temp);
        deleteNode(head_ref_b, temp_b);
        while(temp_b)
        {   
            temp_b->position += 1;
            temp_b = temp_b->next;
        }
    }
}

