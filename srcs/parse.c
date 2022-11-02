#include "push_swap.h"

static  void    array(t_stk *stack, int ac,char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {   
        if(!isNumber(av[i], false))
            printf("Error_!digit\n");
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
    // j = 0;
    
        // printf("%s\n", av);
    
    num = ft_split(av, ' ', items_count);
    // printf("zaaaaab\n");
    while (num[i] &&  0 <= items_count--)
    {
        if(!isNumber(num[i], false))
            printf("Error_!digit\n");

        // printf("num: %d\n", ft_atoi(num[i]));
        append(stack, ft_atoi(num[i]));
        // printf("nooor\n");
        i++;
    }
    // free(&num);
}

t_stk   *parse(int   ac, char    **av)
{
    t_stk   *stack;

    stack = init_stack();
    // printf("nooor\n");
    if (ac == 2)
        string(stack, av[1]);
    else
        array(stack, ac, av); 
    // printf("size:  %zu\n", stack->size);
    if (!stack->size)
        printf("Error_!stack\n");
    return(stack);
}