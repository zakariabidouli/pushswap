#include "push_swap.h"

void up_shift_one(t_stk *stack)
{
    if (stack && stack->head)
		stack->head = stack->head->next;
}

// void r_a(t_stk  *stack)
// {
//     up_shift_one(stack);
//     write(1, "ra\n", 3);
// }

// void r_b(t_stk  *stack)
// {
//     up_shift_one(stack);

// }

// void r_r(t_stk  *stack_a, t_stk  *stack_b)
// {
//     up_shift_one(stack_a);
//     up_shift_one(stack_b);
// }

void    r_a_l(t_stk *stack, t_moves_list *list)
{
    up_shift_one(stack);
    add_command(list, create_command("ra"));
}

void    r_b_l(t_stk *stack, t_moves_list *list)
{
    up_shift_one(stack);
    add_command(list, create_command("rb"));
}

void rr_l(t_stk  *stack_a, t_stk  *stack_b, t_moves_list *list)
{
    up_shift_one(stack_a);
    up_shift_one(stack_b);
    add_command(list, create_command("rr"));
}