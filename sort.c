#include "push_swap.h"

// int stacksize(t_stack *head_a)
// {
//     t_stack     *it;
//     int         i;

//     if(!head_a) 
//         return (0);
//     it = head_a;
//     i = 0;
//     while (it && i++)
//         it = it->next;
//     return (i);
// }
void    in_top(int shift, t_stack *head_a)
{
    t_stack *it;
    int     i;

    it = head_a;
    while (it && --shift >= 0)
        r_a(&it);
}

void    in_flop(int shift, t_stack *head_a)
{
    t_stack *it;
    int     i;

    it = head_a;
    while (it && --shift >= 0)
        rr_a(&it);
}

void    to_top(t_stack *head_a, t_stk_inf *inf)
{
    t_stack  *it;
    int      median;
    int      i;

    median = inf->size / 2;
    i = -1;
    it = head_a;
    while(it && ++i < inf->size)
    {
        if (it->index == 0)
        {
            // printf("################ wsl : %d\n", i);
            if (i + 1 <= median)
                in_top((i), head_a);
            else if (i + 1 > median)
                in_flop((inf->size - i) , head_a);
            // break;
        }
        it = it->next;
    }
    
}
void    to_keep(t_stack *head_a, t_stk_inf *inf)
{
    t_stack *it;

    to_top(head_a, inf);
    it = head_a;
    // while(it)
    // {
    //     if (it->index == 0)
    //         it->keep = true;
    //     else if (it->index >= it->prev->index)
    //         it->keep = true;
    //     else
    //         it->keep = false;
    //     it = it->next;
    // }
}

