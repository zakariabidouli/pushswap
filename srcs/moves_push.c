#include "push_swap.h"


void			push(t_stk *stack,
					t_stack *elem)
{
	t_stack	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->prev;
			elem->prev = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
			stack->head = elem;
		}
		stack->size++;
		// printf("add %zu\n", stack->size);
	}
}

t_stack	*pop(t_stk *stack)
{
	t_stack	*elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			elem->prev = NULL;
			elem->next = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = stack->head->next;
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			elem->prev = NULL;
			elem->next = NULL;
		}
		stack->size--;
	}
	return (elem);
}

void    p_b(t_stk *stack_a,  t_stk *stack_b)
{
    t_stack   *to_pop;

    to_pop = pop(stack_a);
    push(stack_b, (to_pop));
	printf("pb\n");
}

void    p_a(t_stk *stack_a,  t_stk *stack_b)
{
    t_stack   *to_pop;

    to_pop = pop(stack_a);
    push(stack_b, (to_pop));
	printf("pa\n");
}

void    p_b_l(t_stk *stack_a,  t_stk *stack_b, t_moves_list *list)
{
    t_stack   *to_pop;

    to_pop = pop(stack_a);
    push(stack_b, (to_pop));
    add_command(list, create_command("pb"));
    printf("p_b\n");
    // printf("\n9ahhhhhba\n");
}
void    p_a_l(t_stk *stack_a,  t_stk *stack_b, t_moves_list *list)
{
    t_stack   *to_pop;

    to_pop = pop(stack_b);
    push(stack_a, (to_pop));
    add_command(list, create_command("pa"));
    printf("p_b\n");
    // printf("\n9ahhhhhba\n");
}

// void    p_b(t_stk *stack_a,t_stk *stack_b)
// {
//     // t_stack *temp_b;
//     // t_stack *temp_a;
//     // int     temp;

//     // temp_b = stack_b->head;
//     // temp_a = stack_a->head;
//     // if(temp_b)
//     // {
//     //     temp = temp_a->num;
//     //     push_front(stack_b->head, temp_a->num, temp_a->index);
//     //     deleteNode(stack_a->head, temp_a);
//     // }
// }

// void p_a(t_stk *stack_a,t_stk *stack_b)
// {
//     // t_stack *temp_b;
//     // t_stack *temp_a;
//     // int     temp;

//     // temp_a = stack_a->head;
//     // temp_b = stack_b->head;
//     // if(temp_a)
//     // {
//     //     temp = temp_b->num;
//     //     push_front(stack_a->head, temp, temp_a->index);
//     //     deleteNode(stack_b->head, temp_b);
//     // }
// }