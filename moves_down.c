#include "push_swap.h"

void down_shift_one(t_stk *stack)
{
    // printf("saaalam\n");
    if (stack && stack->head)
		stack->head = stack->head->prev;
    // printf("saaalam\n");
    
    // t_stack *temp;
    // int     i;

    // temp = stack->head;
    // while(temp->next!=NULL)
    // {
    //     temp=temp->next;
    // }

    // temp->next = stack->head;
    // stack->head->prev = temp;

    // stack->head = stack->head->prev;
    // temp= temp->prev;
    // temp->next = NULL;
    // stack->head->prev = NULL;
}

void rr_a(t_stk  *stack)
{
    down_shift_one(stack);
    printf("rr_a\n");
}

void rr_b(t_stk  *stack)
{
    down_shift_one(stack);
    printf("rr_b\n");
}

void rr_r(t_stk  *stack_a, t_stk  *stack_b)
{
    down_shift_one(stack_a);
    down_shift_one(stack_b);
    printf("rr_r\n");
}