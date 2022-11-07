#include "push_swap.h"

// void    in_top(int shift, t_stk *stack)
// {;
//     while (--shift >= 0)
//         r_a(stack);
// }

// void    in_flop(int shift, t_stk *stack)
// {
//     while (--shift >= 0)
//         rr_a(stack);
// }

// void    to_top(t_stk *stack)
// {
//     t_stack  *it;
//     size_t      median;
//     size_t      i;

//     median = stack->size / 2;
//     i = 0;
//     it = stack->head;
//     while(it && i < stack->size)
//     {
//         if (it->index == 0)
//         {
//             if ((i + 1)<= median)
//             {
//                 in_top(i, stack);
//             }
//             else if ((i + 1) > median)
//                 in_flop((stack->size - i) , stack);
//             break;
//         }
//         it = it->next;
// 		i++;
//     }
// }

size_t	markup_index(t_stk *stack, t_stack *markup_head)
{
	size_t			index;
	size_t			pairs;
	t_stack         *current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep = true;
		current = markup_head->next;

		while (current->num != markup_head->num && current->next)
		{
			if (current->index == index + 1)
			{
				pairs++;
				index++;
				current->keep = true;
			}
			else
				current->keep = false;
			current = current->next;
		}
	}
	return (pairs);
}

size_t	markup_greater(t_stk *stack, t_stack *markup_head)
{
	size_t			index;
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
		// to_top(stack);
		i = 1;
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
	markup(stack, stack->markup_head);
}
