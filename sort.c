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

    it = head_a;
    while (it && )
}

void    to_top(t_stack *head_a, t_stk_inf *inf)
{
    int      median;
    t_stack *it;
    int      i;

    median = inf->size / 2;
    it = head_a;
    i = -1;
    while(it && ++i)
    {
        if (it->index == 0 && i <= median)
        {
            in_top((i+1), head_a);
            break;
        }
        else if (it->index == 0 && i > median)
        {
           in_flop((inf->size - i) , head_a);
            break;  
        }
        it = it->next;
    }
    
}
void    to_keep(t_stack *head_a, t_stk_inf *inf)
{
    t_stack *it;

    it = head_a;
    while(it)
    {
        // if ( it->index == 0)
        //     it->keep = true;
        if (it->index >= it->prev->index)
            it->keep = true;
        else
            it->keep = false;    
        it = it->next;
    }
}

