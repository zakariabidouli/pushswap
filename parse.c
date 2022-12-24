/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:14 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/24 01:22:31 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	array(t_stk *stack, char *av)
{
	if (!is_num(av))
		terminated("Error");
	append(stack, ft_atoi(av));
}

static void	string(t_stk *stack, char *av)
{
	char	**num;
	int		i;
	int		*items_count;

	i = 0;
	items_count = 0;
	num = ft_split(av, ' ', items_count);
	while (num[i] && 0 <= items_count--)
	{
		if (!is_num(num[i]))
			terminated("Error");
		append(stack, ft_atoi(num[i]));
		i++;
	}
	split_free(&num);
}

static int	is_mult(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && is_num(&str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

t_stk	*parse(int ac, char **av)
{
	t_stk	*stack;
	int		i;

	stack = init_stack();
	i = 1;
	while (ac >= 2 && av[i])
	{
		if (is_mult(av[i]))
			string(stack, av[i]);
		else
			array(stack, av[i]);
		i++;
	}
	if (!stack->size)
		terminated("Error");
	return (stack);
}
