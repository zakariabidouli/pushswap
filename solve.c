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

t_moves_list		*solve(t_stk	*stack_a,size_t(markup)(t_stk *stack, t_stack *markup_head))
{
    t_moves_list     *command_list;
    t_stk           *stack_b;

    command_list = init_moves();
    stack_b = init_stack();
    if(stack_a && stack_b && command_list)
    // {
        // printf("#######wsslat\n");
        crack_a(stack_a, stack_b, markup, command_list);
    // }
    // printf("saaalam\n");
    // {   
        // crack_b(stack_b, stack_b, markup, command_list);
    // crack_b(stack_a, stack_b, markup(stack, markup_head), command_list);
    return (command_list);

}