#include "push_swap.h"

void push_front(t_stack *head_ref, int num, int index)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
 
    new_node->num = num;
    new_node->index = index;

    new_node->next = head_ref;
    new_node->prev = NULL;
 
    if (head_ref != NULL)
        head_ref->prev = new_node;
 
    head_ref = new_node;
}

// void insertAfter(t_stack *prev_node, t_stack *new_node,int num, int index)
// {
//     // t_stack *new_node;
//     printf("zzzzaaaaaab\n");

//     if (prev_node == NULL)
//         return; 
//     // new_node = create_node(num, index);
//     prev_node->next = new_node;
//     new_node->prev = prev_node;
//     new_node->next = NULL;
//     // new_node->prev = prev_node;
//     // if (new_node->next != NULL)
//     //     new_node->next->prev = new_node;
// }

t_stack *create_node(int num)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->num = num;
    new_node->index = -1;
    new_node->keep = false;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}

void append(t_stk   *stack, int num)
{
    t_stack *new_node;
    t_stack *last;

    new_node = create_node(num);
    if(stack && new_node)
    {
        if (!stack->head)
		{
			stack->head = new_node;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			last = stack->head->prev;
			new_node->prev = last;
			last->next = new_node;
			new_node->next = stack->head;
			stack->head->prev = new_node;
		}
		stack->size++;
    }
}

    

void deleteNode(t_stack *head_ref, t_stack* del)
{
    if (head_ref == NULL || del == NULL)
        return;
 
    if (head_ref == del)
        head_ref = del->next;
 
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);
    return;
}

void	free_stack(t_stk *stack)
{
	size_t			i;
	t_stack	        *current;
	t_stack	        *delete;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		delete = current;
		current = current->next;
		free(delete);
		i++;
	}
	free(stack);
}