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
    int j;

    i = 0;
    j = 0;
    
        // printf("%s\n", av);
    
    num = ft_split(av, ' ', 0);
    // printf("zaaaaab\n");
    while (num[i])
    {
        if(!isNumber(num[i], false))
            printf("Error_!digit\n");
        append(stack, ft_atoi(num[i]));
        // printf("nooor\n");
        i++;
    }
    // free(&num);
}

t_stk   *parse(int   ac, char    **av)
{
    t_stk   *stack;

    if(!(stack = (t_stk *) malloc(sizeof(t_stk))))
        printf("Errorallocating memory");
    stack->head = NULL;
    stack->markup_head = NULL;
    stack->size = 0;
    stack->pairs = 0;
    // printf("nooor\n");
    if (ac == 2)
        string(stack, av[1]);
    else
        array(stack, ac, av); 
    printf("size:  %zu\n", stack->size);
      
    if (!stack->size)
        printf("Error_!stack\n");
    return(stack);
}