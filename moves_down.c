#include "push_swap.h"

void down_shift_one(t_stk *stack)
{
    if (stack && stack->head)
        stack->head = stack->head->prev;
}

void rr_a_l(t_stk *stack, t_moves_list *list)
{
    down_shift_one(stack);
    add_command(list, create_command("rra"));
}

void rr_b_l(t_stk *stack, t_moves_list *list)
{
    down_shift_one(stack);
    add_command(list, create_command("rrb"));
}

void rr_r_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list)
{
    down_shift_one(stack_a);
    down_shift_one(stack_b);
    add_command(list, create_command("rrr"));
}