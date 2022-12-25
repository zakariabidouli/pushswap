/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_utl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:42:26 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 03:43:43 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_flag	*init_flag(void)
{
	t_flag	*flag;

	flag = (t_flag *)ft_memalloc(sizeof(t_flag));
	if (!flag)
		terminated("Error");
	flag->flag_a = NULL;
	flag->flag_b = NULL;
	flag->a_moves = Rot;
	flag->a_moves = Rot;
	flag->size = 0;
	flag->is_done = false;
	return (flag);
}

t_stack	*a_element(t_stk *stack, int index)
{
	t_stack	*current;

	current = stack->markup_head;
	if (index < current->index)
	{
		while (index < current->prev->index
			&& current->index > current->prev->index)
			current = current->prev;
	}
	else
	{
		while (index > current->index
			&& current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}

void	up_down(t_stk *stack, int index, size_t *r, size_t *rr)
{
	t_stack	*current;

	if (stack && stack->head)
	{
		current = stack->head;
		while (current->index != index)
		{
			(*r)++;
			current = current->next;
		}
		current = stack->head;
		while (current->index != index)
		{
			(*rr)++;
			current = current->prev;
		}
	}
}

void	set_flag(size_t moves, t_flag new_flag, t_flag *info)
{
	if (info->is_done == false || moves < info->size)
	{
		info->flag_a = new_flag.flag_a;
		info->flag_b = new_flag.flag_b;
		info->a_moves = new_flag.a_moves;
		info->b_moves = new_flag.b_moves;
		info->size = moves;
		info->is_done = true;
	}
}

void	cal(t_stk *stack_a, t_stk *stack_b, t_stack *b, t_flag *info)
{
	t_flag	new_flag;
	size_t	ra_move;
	size_t	rra_move;
	size_t	rb_move;
	size_t	rrb_move;

	ra_move = 0;
	rra_move = 0;
	rb_move = 0;
	rrb_move = 0;
	new_flag.flag_a = a_element(stack_a, b->index);
	new_flag.flag_b = b;
	up_down(stack_a, new_flag.flag_a->index, &ra_move, &rra_move);
	up_down(stack_b, b->index, &rb_move, &rrb_move);
	new_flag.a_moves = Rot;
	new_flag.b_moves = Rot;
	set_flag(max(ra_move, rb_move), new_flag, info);
	new_flag.a_moves = RevRot;
	set_flag(rra_move + rb_move, new_flag, info);
	new_flag.b_moves = RevRot;
	set_flag(max(rra_move, rrb_move), new_flag, info);
	new_flag.a_moves = Rot;
	set_flag(ra_move + rrb_move, new_flag, info);
}
