#include "push_swap.h"

static t_bool needs_pb(t_stk *stack_a)
{
	size_t i;
	t_stack *current;

	if (stack_a)
	{
		i = 0;
		current = stack_a->head;
		while (i < stack_a->size)
		{
			if (!current->keep)
				return (true);
			i++;
			current = current->next;
		}
	}
	return (false);
}

static t_bool needs_sa(t_stk *stack_a,
					   size_t (*markup)(t_stk *, t_stack *))
{
	size_t current_pairs;

	if (stack_a && stack_a->size >= 2)
	{
		s_a(stack_a);
		current_pairs = markup(stack_a, stack_a->markup_head);
		s_a(stack_a);
		markup(stack_a, stack_a->markup_head);
		if (current_pairs > stack_a->pairs)
			return (true);
	}
	return (false);
}

void crack_a(t_stk *stack_a, t_stk *stack_b, size_t markup(t_stk *, t_stack *), t_moves_list *command_list)
{
	while (needs_pb(stack_a))
	{
		if (needs_sa(stack_a, markup))
		{
			s_x_l(stack_a, command_list);
			stack_a->pairs = markup(stack_a, stack_a->markup_head);
		}
		else if (stack_a->head->keep == false)
			p_b_l(stack_a, stack_b, command_list);
		else
			r_a_l(stack_a, command_list);
	}
}