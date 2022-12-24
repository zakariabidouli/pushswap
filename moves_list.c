/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:46:57 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/24 01:18:25 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*create_command(const char *name)
{
	t_moves	*command;

	command = (t_moves *)malloc(sizeof(t_moves));
	if (!command)
		terminated("malloc error");
	command->name = ft_strdup(name);
	if (!command->name)
		terminated("malloc error");
	command->next = NULL;
	return (command);
}

void	add_command(t_moves_list *list,
					t_moves *command)
{
	t_moves	*last;

	if (list && command)
	{
		if (!list->head)
			list->head = command;
		else
		{
			last = list->head;
			while (last->next)
				last = last->next;
			last->next = command;
		}
		list->size++;
	}
}
