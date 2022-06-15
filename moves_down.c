#include "push_swap.h"

void down_shift_one(t_stack **head_ref)
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

    *head_ref = (*head_ref)->prev;
    temp= temp->prev;
    temp->next = NULL;
    (*head_ref)->prev = NULL;
}

void rr_a(t_stack  **head_ref)
{
    down_shift_one(head_ref);
    printf("rr_a\n");
}

void rr_b(t_stack  **head_ref)
{
    down_shift_one(head_ref);
    printf("rr_b\n");
}

void rr_r(t_stack  **head_ref_a, t_stack  **head_ref_b)
{
    down_shift_one(head_ref_a);
    down_shift_one(head_ref_b);
    printf("rr_r\n");
}