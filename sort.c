/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:37 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/24 01:33:00 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	markup_index(t_stk *stack, t_stack *markup_head)
{
	int		index;
	size_t	pairs;
	t_stack	*current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep = true;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index == (index + 1))
			{
				pairs++;
				index++;
				current->keep = true;
			}
			else
				current->keep = false;
			current = current->next;
		}
	}
	return (pairs);
}

size_t	markup_greater(t_stk *stack, t_stack *markup_head)
{
	int		index;
	size_t	pairs;
	t_stack	*current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep = true;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep = true;
			}
			else
				current->keep = false;
			current = current->next;
		}
	}
	return (pairs);
}

void	to_keep(t_stk *stack,
				size_t (*markup)(t_stk *, t_stack *))
{
	size_t	i;
	size_t	current_pairs;
	t_stack	*current;

	if (stack)
	{
		i = 0;
		current = stack->head;
		while (i < stack->size)
		{
			current_pairs = markup(stack, current);
			if (current_pairs > stack->pairs)
			{
				stack->markup_head = current;
				stack->pairs = current_pairs;
			}
			else if (current_pairs == stack->pairs
				&& (!stack->markup_head
					|| current->num < stack->markup_head->num))
				stack->markup_head = current;
			i++;
			current = current->next;
		}
	}
	markup(stack, stack->markup_head);
}
