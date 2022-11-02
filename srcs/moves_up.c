#include "push_swap.h"

void up_shift_one(t_stk *stack)
{
    // t_stack *temp;
    // int     i;

    if (stack && stack->head)
		stack->head = stack->head->next;

    // temp = stack->head;
    // while(temp->next!=NULL)
    // {
    //     temp=temp->next;
    // }
    // temp->next = stack->head;
    // stack->head->prev = temp;

    // stack->head = stack->head->next;
    // temp= temp->next;
    // temp->next = NULL;
    // stack->head->prev = NULL;
}

void r_a(t_stk  *stack)
{
    up_shift_one(stack);
    printf("r_a\n");
}

void r_b(t_stk  *stack)
{
    up_shift_one(stack);
    printf("r_b\n");
}

void r_r(t_stk  *stack_a, t_stk  *stack_b)
{
    up_shift_one(stack_a);
    up_shift_one(stack_b);
    // printf("r_r\n");
}

void    r_a_l(t_stk *stack, t_moves_list *list)
{
    up_shift_one(stack);
    add_command(list, create_command("ra"));
    // printf("ra\n");
    // printf("heeere\n");
}

void    r_b_l(t_stk *stack, t_moves_list *list)
{
    up_shift_one(stack);
    add_command(list, create_command("rb"));
    // printf("rb\n");
    // printf("heeere\n");
}

void rr_l(t_stk  *stack_a, t_stk  *stack_b, t_moves_list *list)
{
    up_shift_one(stack_a);
    up_shift_one(stack_b);
    add_command(list, create_command("rr"));
    // printf("r_r\n");
}