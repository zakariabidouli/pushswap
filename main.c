#include "push_swap.h"

t_stack     *get_min(t_stack  **s, t_stk_inf *inf)
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
		curr = *s;
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

void		sort_position(t_stack **h, t_stk_inf *inf)
{ 
	size_t		index;
	t_stack	    *current;

    current = *h;
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

int main(int ac, char **av)
{
    t_stack         *head_a;
    t_stack         *head_b;
    t_stack         *s;
    // t_stack         *f;
    t_stk_inf       info;
    char            *tmp;
    int             *i = NULL;
    int             j;
    int             z;

    head_a = NULL;
    head_b = NULL;
    if (ac >= 1)
    {
        tmp = malloc(sizeof(char) * (ac - 1));
        if(*tmp)
            return 0;
        z = 1;
        while(av[z])
        {
            tmp[z - 1] = *av[z];
            // while (*tmp)
            // {
            //     if (*tmp == ' ')
            //         *tmp = '\0';
            //     tmp++;
            // }
            if (av[z][0] != '\0')
                append(&head_a, ft_atoi(&tmp[z -1]), -1);
            z++;
        }
        // j = -1;
        // while(tmp[++j])
        // {
        //    append(&head_a, ft_atoi(&tmp[j]), -1);
        // }
        s = head_a;
        
        while(s) 
        {
            printf("################ :%d\n", s->num);
            // printf("################ :%d\n", f->num);
            // printf("################ \n");
            printf("################ :%d\n", s->index);
            printf("################ :%u\n", s->keep);
             // printf("################ :%d\n", f->position);
            printf("################ \n");

            s =  s->next;
            // f =  f->next;
        }
        info.size = j;
        info.head_a = &head_a;
        info.head_b = &head_b;
        s = head_a;
        // f = head_b;
        sort_position(&head_a, &info);
        to_keep(&head_a, &info);
        // sort(head_a, head_b, &info_a);
        // rr_a(&head_a);
        // rr_a(&head_a);
        // r_a(&head_a);
        // r_a(&head_a);
        // r_a(&head_a);
        // s = head_a;
        // f = head_b;
        // while(s) 
        // {
        //     printf("################ :%d\n", s->num);
        //     printf("################ :%d\n", f->num);
        //     printf("################ \n");
        //     printf("################ :%d\n", s->index);
        //     printf("################ :%u\n", s->keep);
        //      printf("################ :%d\n", f->position);
        //     printf("################ \n");

        //     s =  s->next;
        //     f =  f->next;
        // }
    }
}