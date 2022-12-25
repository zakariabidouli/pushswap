/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:22 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 03:44:20 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	duplicated(t_stk *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	size_t	i;

	i = 0;
	tmp = stack->head;
	while (i < stack->size)
	{
		tmp2 = tmp->next;
		while (tmp != tmp2)
		{
			if (tmp->num == tmp2->num)
			{
				terminated("Error");
			}
			else
				tmp2 = tmp2->next;
		}
		i++;
		tmp = tmp->next;
	}
}

t_stack	*get_min(t_stk *s)
{
	size_t	i;
	t_bool	has_min;
	t_stack	*min;
	t_stack	*curr;

	min = NULL;
	if (s)
	{
		i = 0;
		has_min = false;
		curr = s->head;
		while (i < s->size)
		{
			if ((curr->index == -1) && (!has_min || curr->num < min->num))
			{
				has_min = true;
				min = curr;
			}
			i++;
			curr = curr->next;
		}
	}
	return (min);
}

void	sort_position(t_stk *h)
{
	size_t	index;
	t_stack	*current;

	current = NULL;
	index = 0;
	while (1)
	{
		current = get_min(h);
		if (!current)
			break ;
		current->index = index;
		index++;
	}
}

int	main(int ac, char **av)
{
	t_stk			*stack_index;
	t_stk			*stack_greater;
	t_moves_list	*cmd_list_index;
	t_moves_list	*cmd_list_greater;

	if (ac >= 2)
	{
		duplicated((stack_index = parse(ac, av)));
		sort_position(stack_index);
		to_keep(stack_index, &sort_index);
		cmd_list_index = solve(stack_index, &sort_index);
		free_stack(stack_index);
		duplicated((stack_greater = parse(ac, av)));
		sort_position(stack_greater);
		to_keep(stack_greater, &sort_greater);
		cmd_list_greater = solve(stack_greater, &sort_greater);
		free_stack(stack_greater);
		if (cmd_list_index->size < cmd_list_greater->size)
			print_c(cmd_list_index);
		else
			print_c(cmd_list_greater);
		free_c(cmd_list_index);
		free_c(cmd_list_greater);
	}
	return (0);
}
