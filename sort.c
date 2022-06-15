#include "push_swap.h"

void    to_keep(t_stack *head_a, t_stk_inf *inf)
{
    t_stack *it;
    int      i;

    it = head_a;
    i = -1;
    while(it)
    {
        if (it->index == ++i)
        {
            it->keep = true;
        }
        else
        {
            it->keep = false;    
            it = it->next;
        }
    }
}