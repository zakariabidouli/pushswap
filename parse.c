#include "push_swap.h"

static  void    array(t_stk *stack, int ac,char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {   
        if(!is_int(av[i], false))
            terminated("Error\n");
        append(stack, ft_atoi(av[i]));
        i++;
    }
}

static  void    string(t_stk *stack, char *av)
{
    char **num;
    int i;
    int *items_count;

    i = 0;
    items_count = 0;
    num = ft_split(av, ' ', items_count);
    while (num[i] &&  0 <= items_count--)
    {
        if(!is_int(num[i], false))
            terminated("Error\n");
        append(stack, ft_atoi(num[i]));
        i++;
    }
}

t_stk   *parse(int   ac, char    **av)
{
    t_stk   *stack;

    stack = init_stack();
    if (ac == 2 && is_num(av[1]))
        string(stack, av[1]);
    else
        array(stack, ac, av);
    if (!stack->size)
        terminated("Error\n");
    return(stack);
}