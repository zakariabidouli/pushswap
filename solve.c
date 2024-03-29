/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:33 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 01:21:12 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stk	*init_stack(void)
{
	t_stk	*stack;

	stack = (t_stk *)malloc(sizeof(t_stk));
	if (!stack)
		terminated("Error");
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	return (stack);
}

t_moves_list	*init_moves(void)
{
	t_moves_list	*command_list;

	command_list = (t_moves_list *)malloc(sizeof(t_moves_list));
	if (!command_list)
		terminated("Error");
	command_list->head = NULL;
	command_list->size = 0;
	return (command_list);
}

static void	count(t_stk *stack_a, size_t *ra_move, size_t *rra_move)
{
	t_stack	*it;

	it = stack_a->head;
	ra_move = 0;
	while (it->index != 0)
	{
		ra_move++;
		it = it->next;
	}
	it = stack_a->head;
	rra_move = 0;
	while (it->index != 0)
	{
		rra_move++;
		it = it->prev;
	}
}

void	sort_a(t_stk *stack_a, t_moves_list *list)
{
	size_t	ra_move;
	size_t	rra_move;

	if (stack_a && stack_a->head)
	{
		count(stack_a, &ra_move, &rra_move);
		while (stack_a->head->index != 0 && (ra_move < rra_move))
			r_a_l(stack_a, list);
		while (stack_a->head->index != 0 && (ra_move > rra_move))
			rr_a_l(stack_a, list);
	}
}

t_moves_list	*solve(t_stk *stack_a, size_t(sort)(t_stk *, t_stack *))
{
	t_moves_list	*command_list;
	t_stk			*stack_b;

	command_list = init_moves();
	stack_b = init_stack();
	crack_a(stack_a, stack_b, sort, command_list);
	crack_b(stack_a, stack_b, command_list);
	sort_a(stack_a, command_list);
	free_stack(stack_b);
	return (command_list);
}
