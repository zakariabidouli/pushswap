#include "pushswap.h"

void	print_c(t_moves_list *list)
{
	t_moves	*current;

	current = list->head;
	while (current)
	{
		if (current->name)
			write(1, current->name, ft_strlen(current->name));
		write(1, "\n", 1);
		current = current->next;
	}
}

void	free_c(t_moves_list *list)
{
	t_moves	*current;
	t_moves	*del;

	current = list->head;
	while (current)
	{
		del = current;
		current = current->next;
		free(del->name);
		free(del);
	}
	free(list);
}
