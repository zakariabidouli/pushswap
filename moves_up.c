/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:10 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/24 01:21:30 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_shift_one(t_stk *stack)
{
	if (stack && stack->head)
		stack->head = stack->head->next;
}

void	r_a_l(t_stk *stack, t_moves_list *list)
{
	up_shift_one(stack);
	add_command(list, create_command("ra"));
}

void	r_b_l(t_stk *stack, t_moves_list *list)
{
	up_shift_one(stack);
	add_command(list, create_command("rb"));
}

void	rr_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list)
{
	up_shift_one(stack_a);
	up_shift_one(stack_b);
	add_command(list, create_command("rr"));
}
