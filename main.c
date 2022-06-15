#include "push_swap.h"

t_stack     *get_min(t_stack  *s, t_stk_inf *inf)
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
    return (min);
}

void		sort_position(t_stack *h, t_stk_inf *inf)
{ 
	size_t		index;
	t_stack	    *current;

    current = h;
	index = 0;
	while ((current = get_min(h, inf)))
	{
    	current->index = index++;
    }
}

int main(int ac, char **av)
{
    t_stack         *head_a;
    t_stack         *head_b;
    t_stack         *s;
    // t_stack         *f;
    t_stk_inf       info_a;
    char            **tmp;
    int             *i = NULL;
    int             j;

    head_a = NULL;
    head_b = NULL;
    if (ac == 2)
    {
        tmp = ft_split(av[1], ' ', i);
        j = -1;
        while(tmp[++j])
        {
           append(&head_a, ft_atoi(tmp[j]), -1);
        }
        info_a.size = j;
        sort_position(head_a, &info_a);
        to_keep(head_a, &info_a);

        sort(head_a, head_b, &info_a);

        // s = head_a;
        // // f = head_b;
        // while(s) 
        // {
        //     printf("################ :%d\n", s->num);
        //     // printf("################ :%d\n", f->num);
        //     // printf("################ \n");
        //     printf("################ :%d\n", s->position);
        //     // printf("################ :%d\n", f->position);
        //     printf("################ \n");

        //     s =  s->next;
        // // //     // f =  f->next;
        // }
    }
}