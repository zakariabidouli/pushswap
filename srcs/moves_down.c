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
    printf("rra\n");
}

void rr_b(t_stk  *stack)
{
    down_shift_one(stack);
    printf("rrb\n");
}

void rr_r(t_stk  *stack_a, t_stk  *stack_b)
{
    down_shift_one(stack_a);
    down_shift_one(stack_b);
    printf("rrr\n");
}

void rr_a_l(t_stk  *stack, t_moves_list *list)
{
    down_shift_one(stack);
    add_command(list, create_command("rra"));
    // printf("rra\n");
}

void rr_b_l(t_stk  *stack, t_moves_list *list)
{
    down_shift_one(stack);
    add_command(list, create_command("rra"));
    // printf("rrb\n");
}

void rr_r_l(t_stk  *stack_a, t_stk  *stack_b, t_moves_list *list)
{
    down_shift_one(stack_a);
    down_shift_one(stack_b);
    add_command(list, create_command("rrr"));
    // printf("rrr\n");
}