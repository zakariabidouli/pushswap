#include "push_swap.h"

void    to_keep(t_stack *head_a, t_stk_inf *inf)
{
    t_stack *it;
    int      flag;
    int      i;

    it = head_a;
    i = -1;
    flag = 0;
    while(it)
    {
        
        if (it->index >= flag)
        {            
            flag = it->index;
            it->keep = true;
        }
        else
        {
            it->keep = false;    
        }
        it = it->next;
    }
}

