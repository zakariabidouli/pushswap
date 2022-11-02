#include "push_swap.h"
// #include "unistd.h"

t_stk			*init_stack(void)
{
	t_stk *stack;

	if (!(stack = (t_stk *)malloc(sizeof(t_stk))))
		printf("error creating command\n");
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	return (stack);
}

t_moves_list *init_moves(void)
{
    t_moves_list *command_list;

    if(!(command_list = (t_moves_list *)malloc(sizeof(t_moves_list))))
        printf("error creating command\n");
    command_list->head = NULL;  
    command_list->size = 0;
    return(command_list);  
}

void    count(t_stk *a, size_t *ra_move, size_t *rra_move)
{
    t_stack  *it;

    if(a && a->head)
    {
        it = a->head;
        while(it->index != 0)
        {
            (*ra_move)++;
            it = it->next;
        }
        it = a->head;
        while(it->index != 0)
        {
            (*rra_move)++;
            it = it->prev;
        }        
    }
}

void    sort_a(t_stk    *stack_a, t_moves_list *list)
{
    size_t ra_move;
    size_t rra_move;

    ra_move = 0;
    rra_move = 0;
    count(stack_a, &ra_move, &rra_move);
    while(stack_a->head->index != 0 && (ra_move < rra_move))
        r_a_l(stack_a, list); 
    while(stack_a->head->index != 0 && (ra_move > rra_move)) 
        rr_a_l(stack_a, list); 
}

t_moves_list		*solve(t_stk	*stack_a,size_t(markup)(t_stk *stack, t_stack *markup_head))
{
    t_moves_list     *command_list;
    t_stk           *stack_b;

    command_list = init_moves();
    stack_b = init_stack();
    if(stack_a && stack_b && command_list)
    {
        crack_a(stack_a, stack_b, markup, command_list);
        crack_b(stack_a, stack_b, command_list);
        sort_a(stack_a, command_list);
        free_stack(stack_b);
    }
    // printf("saaalam\n");
    // {   
        // printf("\n#######wsslat\n");
        // crack_b(stack_b, stack_b, markup, command_list);
    // crack_b(stack_a, stack_b, markup(stack, markup_head), command_list);
    return (command_list);

}