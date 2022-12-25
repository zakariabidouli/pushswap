/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:00:24 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 01:20:17 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

static unsigned int	math(const char *s, int i)
{
	int	x;

	x = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		x *= 10;
		x += s[i] - '0';
		i++;
	}
	return (x);
}

long	ft_atoi(const char	*str)
{
	int		i;
	int		j;
	long	x;
	char	*s;

	if (!(str))
		return (0);
	i = 0;
	j = 0;
	s = (char *)str;
	while (s[i] == 32 || (9 <= s[i] && 13 >= s[i]))
		i++;
	if (s[i] == '-' && ++i)
		j++;
	else if (s[i] == '+')
		i++;
	x = math(s, i);
	if (j % 2)
		x = -x;
	if (x > FT_INT_MAX || x < FT_INT_MIN)
		terminated ("Error");
	return (x);
}
