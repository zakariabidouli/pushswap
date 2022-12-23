#include "push_swap.h"

static void array(t_stk *stack, char *av)
{
    if (!is_int(av, false))
        terminated("Error_arr\n");
    append(stack, ft_atoi(av));
}

static void string(t_stk *stack, char *av)
{
    char **num;
    int i;
    int *items_count;

    i = 0;
    items_count = 0;
    num = ft_split(av, ' ', items_count);
    while (num[i] && 0 <= items_count--)
    {
        if (!is_int(num[i], false))
            terminated("Error_str\n");
        append(stack, ft_atoi(num[i]));
        i++;
    }
    split_free(&num);
}

static int is_one(char *av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (av[i] == ' ' && av[i + 1] != ' ')
            return (1);
        i++;
    }
    return (0);
}

t_stk *parse(int ac, char **av)
{
    t_stk *stack;
    int i;

    stack = init_stack();
    i = 1;
    while (ac >= 2 && av[i])
    {
        if (is_one(av[i]))
            string(stack, av[i]);
        else
            array(stack, av[i]);
        i++;
    }
    if (!stack->size)
        terminated("Error\n");
    return (stack);
}