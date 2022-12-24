/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:01 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/24 01:20:05 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stk *stack, t_stack *elem)
{
	t_stack	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->prev;
			elem->prev = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
			stack->head = elem;
		}
		stack->size++;
	}
}

t_stack	*pop(t_stk *stack)
{
	t_stack	*elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			elem->prev = NULL;
			elem->next = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = stack->head->next;
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			elem->prev = NULL;
			elem->next = NULL;
		}
		stack->size--;
	}
	return (elem);
}

void	p_b_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list)
{
	t_stack	*elem;

	elem = pop(stack_a);
	push(stack_b, elem);
	add_command(list, create_command("pb"));
}

void	p_a_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list)
{
	t_stack	*elem;

	elem = pop(stack_b);
	push(stack_a, elem);
	add_command(list, create_command("pa"));
}
