#include "push_swap.h"

int    max(int  a,int b) 
{
    if(a > b) 
        return a;
    return b;
}


void	*ft_memalloc(size_t size)
{
	void *ptr;

	if ((ptr = malloc(size)))
		ft_bzero(ptr, size);
	return (ptr);
}

t_flag *init_flag(void)
{
    t_flag *flag;

    if(!(flag = (t_flag *)ft_memalloc(sizeof(t_flag))))
        return 0;
    flag->flag_a = NULL;
    flag->flag_b = NULL;
    flag->a_moves = 0;
    flag->a_moves = 0;
    flag->size = 0;
    flag->is_done = false;
    return (flag);
}

t_stack *a_element(t_stk *stack, size_t index)
{
    t_stack  *it;

    it = stack->head;
    if(index < it->index)
    {
        while(index < it->prev->index && it->index > it->prev->index)
            it = it->prev;
    }
    else
    {   
        while(index > it->prev->index && it->index < it->prev->index)
                it = it->next;
        if (index > it->index && it->index > it->next->index)
			it = it->next;
    }
    return it;
}

void    up_down(t_stk   *stack, size_t index, size_t *r, size_t *rr)
{
    t_stack *current;

    if(stack && stack->head)
    {
        current = stack->head;
        while(current->index != index)
        {
            (*r)++;
            current = current->next;
        }
        current = stack->head;
        while(current->index != index)
        {    
            (*rr)++;
            current = current->prev;
        }
    }
}

void    set_flag(size_t    moves,t_flag new_flag, t_flag *info)
{
    if(info->is_done == false || moves < info->size)
    {
        info->flag_a = new_flag.flag_a;
		info->flag_b = new_flag.flag_b;
		info->a_moves = new_flag.a_moves;
		info->b_moves = new_flag.b_moves;
		info->size = moves;
		info->is_done = true;
    }

}

void    cal(t_stk *stack_a, t_stk *stack_b, t_stack *b, t_flag *info)
{   
    t_flag   new_flag;
    size_t  ra_move;
    size_t  rra_move;
    size_t  rb_move;
    size_t  rrb_move;

    ra_move = 0;
    rra_move = 0;
    rb_move = 0;
    rrb_move = 0;
    new_flag.flag_a = a_element(stack_a, b->index);
    new_flag.flag_b = b;
    new_flag.a_moves = 0;
    new_flag.b_moves = 0;
    up_down(stack_a, new_flag.flag_a->index, &ra_move, &rra_move);
    up_down(stack_b, b->index, &rb_move, &rrb_move);
    set_flag(max(ra_move , rb_move), new_flag, info);  
    new_flag.a_moves = 1;
    set_flag((rra_move + rb_move), new_flag, info);
    new_flag.b_moves = 1;
    set_flag(max(rra_move , rrb_move), new_flag, info);  
    new_flag.b_moves = 0;
    set_flag((ra_move + rrb_move), new_flag, info);
}


void    calculate_moves(t_stk *stack_a, t_stk *stack_b, t_flag *info)
{
    t_stack *b;
    size_t     i;

    if(stack_b)
    {
        b = stack_b->head;
        i = 0;
        while(i < stack_b->size)
        {
            cal(stack_a, stack_b, b, info);
            i++;
            b = b->next;
        }
    }
}

static void			to_a(t_stk *stack_a, t_stk *stack_b,
						t_flag *info, t_moves_list *command)
{
	while (info->flag_a != stack_a->head || info->flag_b != stack_b->head)
	{
		if (info->a_moves == info->b_moves
			&& info->flag_a != stack_a->head
			&& info->flag_b != stack_b->head)
			(info->a_moves == 0) ?
					rr_l(stack_a, stack_b, command) : rr_r_l(stack_a, stack_b, command);
		else if (info->flag_a != stack_a->head)
			(info->a_moves == 0) ?
                    r_a_l(stack_a, command) : rr_a_l(stack_a, command);
		else if (info->flag_b != stack_b->head)
			(info->b_moves == 0) ?
					r_b_l(stack_b, command) : rr_b_l(stack_b, command);
	}
}

void    crack_b(t_stk *stack_a, t_stk *stack_b, t_moves_list  *command_list)
{   
    t_flag *info;

    if(!(info = init_flag()))
        printf("error_init\n");
    while(stack_b->size)
    {
        info->is_done = false;
        calculate_moves(stack_a, stack_b, info);
        to_a(stack_a, stack_b, info, command_list);
        p_a_l(stack_a, stack_b, command_list);
        
    }
    free(info);
}    