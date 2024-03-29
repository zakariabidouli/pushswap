/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:46:48 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 01:20:41 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	down_shift_one(t_stk *stack)
{
	if (stack && stack->head)
		stack->head = stack->head->prev;
}

void	rr_a_l(t_stk *stack, t_moves_list *list)
{
	down_shift_one(stack);
	add_command(list, create_command("rra"));
}

void	rr_b_l(t_stk *stack, t_moves_list *list)
{
	down_shift_one(stack);
	add_command(list, create_command("rrb"));
}

void	rr_r_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list)
{
	down_shift_one(stack_a);
	down_shift_one(stack_b);
	add_command(list, create_command("rrr"));
}
