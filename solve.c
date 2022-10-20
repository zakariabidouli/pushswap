#include "push_swap.h"



void		solve(t_stk	*stack, size_t(markup)(t_stk *stack, t_stack *markup_head));
{
    t_moves command_list;
    t_stack stack_b;

    init(command_list);
    init(stack_b);
    solve_a(stack, markup(stack, markup_head), command_list);
    solve_b(stack, markup(stack, markup_head), command_list);
    aligne();

}