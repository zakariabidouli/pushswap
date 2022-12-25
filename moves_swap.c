/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:06 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 01:20:48 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap_first(t_stk *stack, t_stack *first, t_stack *second)
{
	t_stack	*previous;
	t_stack	*next;

	previous = first->prev;
	next = second->next;
	previous->next = second;
	second->prev = previous;
	first->next = next;
	next->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void	s_a(t_stk *stack)
{
	swap_first(stack, stack->head, stack->head->next);
}

void	s_s(t_stk *stack_a, t_stk *stack_b)
{
	swap_first(stack_a, stack_a->head, stack_a->head->next);
	swap_first(stack_b, stack_b->head, stack_b->head->next);
}

void	s_x_l(t_stk *stack, t_moves_list *list)
{
	swap_first(stack, stack->head, stack->head->next);
	add_command(list, create_command("sa"));
}
