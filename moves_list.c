#include "push_swap.h"

t_moves		*create_command(const char *name)
{
	t_moves *command;

	if (!(command = (t_moves *)malloc(sizeof(t_moves))))
		printf("malloc error");
	if (!(command->name = ft_strdup(name)))
		printf("malloc error");
	command->next = NULL;
	return (command);
}

void			add_command(t_moves_list *list,
					t_moves *command)
{
	t_moves *last;

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