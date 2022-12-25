/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:46:27 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 01:20:22 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_bool	search_pb(t_stk *stack_a)
{
	size_t	i;
	t_stack	*current;

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

static t_bool	search_sa(t_stk *stack_a,
						size_t (*sort)(t_stk *, t_stack *))
{
	size_t	current_pairs;

	if (stack_a && stack_a->size >= 2)
	{
		s_a(stack_a);
		current_pairs = sort(stack_a, stack_a->markup_head);
		s_a(stack_a);
		sort(stack_a, stack_a->markup_head);
		if (current_pairs > stack_a->pairs)
			return (true);
	}
	return (false);
}

void	crack_a(t_stk *stack_a, t_stk *stack_b,
				size_t sort(t_stk *, t_stack *), t_moves_list *command_list)
{
	while (search_pb(stack_a))
	{
		if (search_sa(stack_a, sort))
		{
			s_x_l(stack_a, command_list);
			stack_a->pairs = sort(stack_a, stack_a->markup_head);
		}
		else if (stack_a->head->keep == false)
			p_b_l(stack_a, stack_b, command_list);
		else
			r_a_l(stack_a, command_list);
	}
}
