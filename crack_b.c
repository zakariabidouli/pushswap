/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:46:34 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 03:43:43 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate_x(t_stk *stack_a, t_stk *stack_b,
					t_flag *info, t_moves_list *command)
{
	if(info->x == 'a')
	{
		if (info->a_moves == Rot)
			r_a_l(stack_a, command);
		else
			rr_a_l(stack_a, command);
	}
	else if(info->x == 'b')
	{
		if (info->b_moves == Rot)
			r_b_l(stack_b, command);
		else
			rr_b_l(stack_b, command);
	}
	else if(info->x == 'r')
	{
		if (info->a_moves == Rot)
			rr_l(stack_a, stack_b, command);
		else
			rr_r_l(stack_a, stack_b, command);
	}
}
static void	rotate(t_stk *stack_a, t_stk *stack_b,
					t_flag *info, t_moves_list *command)
{
	while (info->flag_a != stack_a->head || info->flag_b != stack_b->head)
	{
		if (info->a_moves == info->b_moves
			&& info->flag_a != stack_a->head
			&& info->flag_b != stack_b->head)
		{
			info->x = 'r';
			rotate_x(stack_a, stack_b, info, command);
		}	
		else if (info->flag_a != stack_a->head)
		{
			info->x = 'a';
			rotate_x(stack_a, stack_b, info, command);
		}
		else if (info->flag_b != stack_b->head)
		{
			info->x = 'b';
			rotate_x(stack_a, stack_b, info, command);
		}
	}
}

void	calculate_moves(t_stk *stack_a, t_stk *stack_b, t_flag *info)
{
	t_stack	*b;
	size_t	i;

	if (stack_b)
	{
		i = 0;
		b = stack_b->head;
		while (i < stack_b->size)
		{
			cal(stack_a, stack_b, b, info);
			i++;
			b = b->next;
		}
	}
}

void	crack_b(t_stk *stack_a, t_stk *stack_b, t_moves_list *command_list)
{
	t_flag	*info;

	info = init_flag();
	while (stack_b->size)
	{
		info->is_done = false;
		calculate_moves(stack_a, stack_b, info);
		rotate(stack_a, stack_b, info, command_list);
		p_a_l(stack_a, stack_b, command_list);
	}
	free(info);
}
