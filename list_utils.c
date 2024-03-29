/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:46:39 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 01:20:29 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_front(t_stack *head_ref, int num, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->num = num;
	new_node->index = index;
	new_node->next = head_ref;
	new_node->prev = NULL;
	if (head_ref != NULL)
		head_ref->prev = new_node;
	head_ref = new_node;
}

t_stack	*create_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->num = num;
	new_node->index = -1;
	new_node->keep = false;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	append(t_stk	*stack, int num)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = create_node(num);
	if (stack && new_node)
	{
		if (!stack->head)
		{
			stack->head = new_node;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			last = stack->head->prev;
			new_node->prev = last;
			last->next = new_node;
			new_node->next = stack->head;
			stack->head->prev = new_node;
		}
		stack->size++;
	}
}

void	free_stack(t_stk *stack)
{
	size_t	i;
	t_stack	*current;
	t_stack	*delete;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		delete = current;
		current = current->next;
		free(delete);
		i++;
	}
	free(stack);
}
