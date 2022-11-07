#include "push_swap.h"

void	ft_put_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void terminated(char const *s)
{
    ft_put_fd(s, 2);
    exit(1);
}

void    duplicated(t_stk *stack)
{
    t_stack *tmp;
    t_stack *tmp2;
    size_t     i;

    i = 0;
    tmp = stack->head;
    while (i < stack->size)
    {   
        tmp2 = tmp->next;
        while (tmp != tmp2)
        {
            if (tmp->num == tmp2->num)
            {
                terminated("Error\n");
            }
            else
                tmp2 = tmp2->next;
        }
        i++;
        tmp = tmp->next;
    }
}

t_stack     *get_min(t_stack  *s, t_stk *inf)
{
	size_t	i;
	t_bool	has_min;
	t_stack	*min;
	t_stack	*curr;
    
    min = NULL;
	if (s) 
	{
		i = 0;
		has_min = false;
		curr = s;
		while (i < inf->size)
		{
        if ((curr->index == (size_t)-1)
				&& (!has_min || curr->num < min->num))
			{
				has_min = true;
				min = curr;
			}
			i++;
			curr = curr->next;
		}
	}
    return (min);
}

void		sort_position(t_stack *h, t_stk *inf)
{ 
	size_t		index;
	t_stack	    *current;

	index = 0;
	while ((current = get_min(h, inf)))
	{
    	current->index = index++;
    }
}

void print_c(t_moves_list *list)
{
    t_moves *current;

	current = list->head;
	while (current)
	{
        if (current->name)
	    	write(1, current->name, ft_strlen(current->name));
	    write(1, "\n", 1);
		current = current->next;
	}
}

void free_c(t_moves_list *list)
{
    t_moves *current;
	t_moves *del;

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

int main(int ac, char **av)
{
    t_stk           *stack_idx;
    // t_stack         *s;
    // t_stack         *f;
    t_stk           *stack_greater;
    t_moves_list    *command_list_index;
    t_moves_list    *command_list_greater;

    if(ac >= 2)
    {
        stack_idx = parse(ac, av);
        duplicated(stack_idx = parse(ac, av));
        sort_position(stack_idx->head, stack_idx);
        to_keep(stack_idx, &markup_index );
        command_list_index = solve(stack_idx, &markup_index);
        // free_stack(stack_idx);
        duplicated(stack_greater = parse(ac, av));
        sort_position(stack_greater->head, stack_greater);
        to_keep(stack_greater, &markup_greater);
        command_list_greater = solve(stack_greater, &markup_greater);
        // free_stack(stack_greater);
        if(command_list_index->size < command_list_greater->size)
			print_c(command_list_index);
        print_c(command_list_greater);
        free_c(command_list_index);
        free_c(command_list_greater);
        // s = stack_idx->head;
        // printf("########################## :%d\n\n", s->num);
        // s =  s->next;
        // while(s != stack_idx->head)  
        // {
        //     printf("####################### :%d\n\n", s->num);
        //     s =  s->next;
        // }
        // f = stack_idx->head;
        // printf("GREATER#####################\n\n");
        // printf("########################## :%d\n\n", f->num);
        // f =  f->next;
        // while(f != stack_idx->head)  
        // {
        //     printf("####################### :%d\n\n", f->num);
        //     f =  f->next;
        // }
    }
    else
        terminated("Error");
    return (0);
}
        

        // s_a(stack_idx);
        // r_a(stack_idx);
        // p_b_l(stack_idx, stack_b,command_list);
        // to_keep(stack_idx, markup_greater);
        // mark_index(&stack_idx->head, stack_idx->markup_head);
        // sort(head_a, head_b, &info_a);
        // printf("\nzaaaab\n");
        // rr_a(&stack_idx->head);
        // r_a(&stack_idx->head);
        // print_stack(stack_idx, &stack_idx->markup_head, stack_idx->size);
        // f = command_list_greater->head;
        // while(f)
        // {
        //     printf("###### :%s\n ", f->name);
        //     f = f->next;
        // }