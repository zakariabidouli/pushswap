#include "push_swap.h"

void    new_positions(t_stack  **head_ref)
{
    t_stack *it;
    int       i;

    it = *head_ref;
    i = 0;
    while (it)
    {
        it->position = i++;
        it = it->next;
    }
}

void up_shift_one(t_stack **head_ref)
{
    t_stack *temp;
    int     i;

    temp = *head_ref;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = *head_ref;
    (*head_ref)->prev = temp;

    *head_ref = (*head_ref)->next;
    temp= temp->next;
    temp->next = NULL;
    (*head_ref)->prev = NULL;

    new_positions(head_ref);
}

void r_a(t_stack  **head_ref)
{
    up_shift_one(head_ref);
    printf("r_a\n");
}

void r_b(t_stack  **head_ref)
{
    up_shift_one(head_ref);
    printf("r_b\n");
}

void r_r(t_stack  **head_ref_a, t_stack  **head_ref_b)
{
    up_shift_one(head_ref_a);
    up_shift_one(head_ref_b);
    printf("r_r\n");
}