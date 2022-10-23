#include "push_swap.h"

// int stacksize(t_stack *head_a)
// {
//     t_stack     *it;
//     int         i;

//     if(!head_a) 
//         return (0);
//     it = head_a;
//     i = 0;
//     while (it && i++)
//         it = it->next;
//     return (i);
// }
void    in_top(int shift, t_stk *stack)
{
    // t_stack *it;
    // int     i;

    // it = &head_a;
    // printf("################# in top\n");
    while (--shift >= 0)
        r_a(stack);
}

void    in_flop(int shift, t_stk *stack)
{
    // t_stack *it;
    // int     i;

    // it = head_a;
    // printf("################# in flop\n");
    while (--shift >= 0)
        rr_a(stack);
}

void    to_top(t_stk *stack)
{
    t_stack  *it;
    int      median;
    int      i;

    median = stack->size / 2;
	// printf("median = %d\n", median);
    i = 0;
    it = stack->head;
    while(it && (size_t)i < stack->size)
    {
        if (it->index == 0)
        {
            if ((i + 1)<= median)
            {
                in_top(i, stack);
            }
            else if ((i + 1) > median)
                in_flop((stack->size - i) , stack);
			// printf("\n################ wsl : %d\n", median);
            break;
        }
		i++;
        it = it->next;
    }
}

// void    great_than(t_stack **head_a)
// {
//     t_stack *it;
//     int     new_num;

//     it = *head_a;
//     new_num = 0;
//     while(it)
//     {
//         if (it->index == 0)
//         {
//             it->keep = true;
//             new_num = it->index;
//         }
//         else if (it->index > new_num)
//         {
//             it->keep = true;
//             new_num = it->index;
//         }
//         else
//             it->keep = false;
//         it = it->next;
//     }
// }

// void    mark_index(t_stack **head_a)
// {
//     t_stack *it;
//     int new_index;

//     it = *head_a;
//     new_index = 0;
//     while(it)
//     {
//         if (it->index == 0)
//             it->keep = true;
//         else if (it->index == (new_index + 1))
//         {
//             it->keep = true;
//             new_index = it->index;
//         }
//         else
//             it->keep = false;
//         it = it->next;
//     }

// }

// void    to_keep(t_stack **head, t_stk *inf)
// {
//     t_stack *it;
//     int i;

//     i = -1;
//     it = *head;
//     to_top(head, inf);
//     great_than(head);
//     mark_index(head);
// }

// int    check(t_stack **head)
// {
//     t_stack *it;

//     it = *head;
//     while(it != NULL)
//     {
//         if(it->keep == false)
//             return (0);
//         it = it->next;
//     }
//     return (1);
// }


size_t	markup_index(t_stk *stack,
			t_stack *markup_head)
{
	ssize_t			index;
	size_t			pairs;
	t_stack         *current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		// printf("mark:  %zu\n", markup_head->index);

		markup_head->keep = true;
		current = markup_head->next;
		// printf("mark 1:  %d\n", markup_head->num);

		while (current->num != markup_head->num && current->next)
		{
			if (current->index == index + 1)
			{
				// printf("current 1: %d\n", current->num);
				pairs++;
				index++;
				current->keep = true;
			}
			else
			{
				// printf("current 2: %d\n", current->num);
				current->keep = false;
			}		
			current = current->next;
		}
	}
	
			// printf("\nzaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa : %zu\n", pairs);
	return (pairs);
}

size_t	markup_greater(t_stk *stack,
			t_stack *markup_head)
{
	ssize_t			index;
	size_t			pairs;
	t_stack	        *current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep = true;
		current = markup_head->next;
		while (current != markup_head &&  current)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep = true;
			}
			else
				current->keep = false;
			current = current->next;
		}
	}
	return (pairs);
}

void	to_keep(t_stk *stack,
			size_t (*markup)(t_stk *, t_stack *))
{
	size_t			i;	
	size_t			current_pairs;
	t_stack	        *current;

	if (stack)
	{
		to_top(stack);
		// printf("stack\n\n");
		i = 1;
		// printf("zaaabn\n");	
		current = stack->head;
		
		while (i < stack->size && current->next && current)
		{
			current_pairs = markup(stack, current);
			if (current_pairs > stack->pairs)
			{
				stack->markup_head = current;
				stack->pairs = current_pairs;
			}
			else if (current_pairs == stack->pairs &&  
				(!stack->markup_head || 
							current->num < stack->markup_head->num))
				stack->markup_head = current;
			i++;
			current = current->next;
		}
	}
	// printf("zzzzzaaab: %zu\n", stack->pairs);
	markup(stack, stack->markup_head);
}

// void count(t_stack **head, t_stk_inf *inf)
// {
//     t_stack *it;
//     int      num;

//     it = *inf->head_a;
//     while (check(&it) == 0)
//     {
//         if(it->keep == true)
//         {
//            s_a(&it);
//            great_than(&it); 
//         }
//         else if (it->keep == false)
//         {
//             p_b(&it, inf->head_b);
//         }
//         else
//             r_a(&it);
//         it = it->next;
//     }
// }
