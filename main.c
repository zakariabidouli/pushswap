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


int main(int ac, char **av)
{
    t_stk         *stack_idx;
    t_stack         *s;
    // t_stack         *f;
    // t_stk_inf       *info;
    
    if(ac >= 2)
    {
        stack_idx = parse(ac, av);
        duplicated(stack_idx);
        sort_position(stack_idx->head, stack_idx);
        // to_keep(stack_idx->head, stack_idx);
        // sort(head_a, head_b, &info_a);
        s = stack_idx->head;
        // printf("\nzaaaab\n");
        while(s) 
        {
            printf("\nzaaaab\n");

            printf("################ zaab:%d\n", s->num);
            // printf("################ :%d\n", f->num);
            // printf("################ \n");
            printf("################ zaab-index:%d\n", s->index);
            printf("################ :%u\n", s->keep);
                // printf("################ :%d\n", f->position);
            printf("################ \n");

            s =  s->next;
            // f =  f->next;
        }
        // rr_a(&head_a);
        // rr_a(&head_a);
        // r_a(&head_a);
        // r_a(&head_a);
        // r_a(&head_a);
        // s = head_a;
        // f = head_b;
        // s = stack_idx->head_a;
        // while(s) 
        // {
        //     printf("################ :%d\n", s->num);
        //     printf("################ :%d\n", f->num);
        //     printf("################ \n");
        //     // printf("################ :%d\n", s->index);
        //     // printf("################ :%u\n", s->keep);
        //     //  printf("################ :%d\n", f->position);
        //     printf("################ \n");

        //     s =  s->next;
        //     // f =  f->next;
        // }
    }
    else
        printf("Error_info\n");
    return (0);
}
