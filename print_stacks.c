/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:18 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/24 01:43:39 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_unsignedlen(uintmax_t number, unsigned int base)
{
	size_t	size;

	if (base >= 2)
	{
		size = 1;
		while ((number /= base))
			size++;
	}
	else
		size = 0;
	return (size);
}

size_t	ft_signedlen(intmax_t number, unsigned int base)
{
	size_t	size;

	size = ft_unsignedlen((uintmax_t)my_abs(number), base);
	return (size + ((number < 0 && size) ? 1 : 0));
}
static void	print_int(int number,
				size_t len)
{
	size_t	spaces;
	size_t	numlen;

	numlen = ft_signedlen(number, 10);
	spaces = len - numlen;
	while (spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		spaces--;
	}
	ft_putnbr_fd(number, 1);
}

static void	print_stack(t_stk *stack,
				t_stack **current,
				size_t i)
{
	if (i < stack->size)
	{
		ft_putchar_fd(' ', 1);
		print_int((*current)->num, ft_signedlen(FT_INT_MIN, 10));
		ft_putchar_fd(' ', 1);
		(*current) = (*current)->next;
	}
	else
		ft_putstr_fd("             ", 1);
}

void		print_stacks(t_stk *a_stack,
				t_stk *b_stack,
				t_bool color)
{
	size_t			i;
	t_stack	*a_current;
	t_stack	*b_current;

	i = 0;
	a_current = a_stack->head;
	b_current = b_stack->head;
	ft_putstr_fd("+------A------+------B------+\n", 1);
	while (i < a_stack->size || i < b_stack->size)
	{
		if (!(i % 2) && color)
			ft_putstr_fd(COL, 1);
		ft_putchar_fd('|', 1);
		print_stack(a_stack, &a_current, i);
		ft_putchar_fd('|', 1);
		print_stack(b_stack, &b_current, i);
		ft_putchar_fd('|', 1);
		if (!(i % 2) && color)
			ft_putstr_fd(RESET_COL, 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	// terminated("+-------------+-------------+");
}