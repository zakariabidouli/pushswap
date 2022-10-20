#include "push_swap.h"

void    duplicated(t_stk *stack)
{
    t_stack *tmp;
    t_stack *tmp2;
    int     i;

    tmp = stack->head;
    i = 0;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->num == tmp2->num)
            {
                printf("duplicated value : %d\n", tmp->num);
                exit(0);
            }
            tmp2 = tmp2->next;
        }
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
			if ((curr->index == -1)
				&& (!has_min || curr->num < min->num))
			{
				has_min = true;
				min = curr;
			}
			i++;
			curr = curr->next;
		}
	}
    // printf("%d is min\n", min->num);
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

// void init_inf(t_stack *head_a, t_stack *head_b)
// {
//     t_stk_inf info;

// }
static void ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb == 0)
	{
		ft_putchar_fd ('0', fd);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd ('-', fd);
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr > 9)
	{
		ft_putnbr_fd (nbr / 10, fd);
		ft_putnbr_fd (nbr % 10, fd);
	}
	else
		ft_putchar_fd (nbr + '0', fd);
}

static  void ft_putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}



static void	print_stack(t_stk *stack,
				t_stack **current,
				size_t i)
{
	if (i < stack->size)
	{
		ft_putchar(' ');
		printf("%d", (*current)->num);
		ft_putchar(' ');
		(*current) = (*current)->next;
	}
	else
		ft_putstr("             ");
}

int main(int ac, char **av)
{
    t_stk           *stack_idx;
    t_stack         *s;
    // t_stack         *f;
    // t_stk_inf       *info;
    
    if(ac >= 2)
    {
        // stack_idx = parse(ac, av);
        duplicated(stack_idx = parse(ac, av));
        sort_position(stack_idx->head, stack_idx);
        to_keep(stack_idx, markup_index);
        // to_keep(stack_idx, markup_greater);
        stack_idx = solve(stack_idx, markup(stack_idx, markup_index));
        // free_stack(stack_idx);
        // mark_index(&stack_idx->head, stack_idx->markup_head);
        // sort(head_a, head_b, &info_a);
        // printf("\nzaaaab\n");
        // rr_a(&stack_idx->head);
        // r_a(&stack_idx->head);
        // print_stack(stack_idx, &stack_idx->markup_head, stack_idx->size);
        // s = stack_idx->head_a;
        // s = stack_idx->head;
        // while(s) 
        // {
        //     printf("################ :%d\n", s->num);
        //     // printf("################ :%d\n", f->num);
        //     printf("################ \n");
        //     printf("################ :%zd\n", s->index);
        //     printf("################ :%u\n", s->keep);
        //     //  printf("################ :%d\n", f->position);
        //     printf("################ \n");

        //     s =  s->next;
        //     // f =  f->next;
        // }
    }
    else
        printf("Error_args\n");
    return (0);
}
