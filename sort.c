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
void    in_top(int shift, t_stack **head_a)
{
    t_stack *it;
    int     i;

    it = *head_a;
    // printf("################# in top\n");
    while (it && --shift >= 0)
        r_a(head_a);
}

void    in_flop(int shift, t_stack **head_a)
{
    t_stack *it;
    int     i;

    it = *head_a;
    // printf("################# in flop\n");
    while (it && --shift >= 0)
        rr_a(head_a);
}

void    to_top(t_stack **head_a, t_stk_inf *inf)
{
    t_stack  *it;
    int      median;
    int      i;

    median = inf->size / 2;
    i = -1;
    it = *head_a;
    while(it && ++i < inf->size)
    {
        if (it->index == 0)
        {
            if (i + 1 <= median)
            {
                // printf("################ wsl : %d\n", i);
                in_top((i), head_a);
            }
            else if (i + 1 > median)
                in_flop((inf->size - i) , head_a);
            // break;
        }
        it = it->next;
    }
    
}
void    great_than(t_stack **head_a)
{
    t_stack *it;
    int     new_num;

    it = *head_a;
    new_num = 0;
    while(it)
    {
        if (it->index == 0)
        {
            it->keep = true;
            new_num = it->index;
        }
        else if (it->index > new_num)
        {
            it->keep = true;
            new_num = it->index;
        }
        else
            it->keep = false;
        it = it->next;
    }
}

void    mark_index(t_stack **head_a)
{
    t_stack *it;
    int new_index;

    it = *head_a;
    new_index = 0;
    while(it)
    {
        if (it->index == 0)
            it->keep = true;
        else if (it->index == (new_index + 1))
        {
            it->keep = true;
            new_index = it->index;
        }
        else
            it->keep = false;
        it = it->next;
    }

}

void    to_keep(t_stack **head_a, t_stk_inf *inf)
{
    t_stack *it;
    int i;

    i = -1;
    it = *head_a;
    to_top(head_a, inf);
    great_than(head_a);
    // mark_index(head_a);
}

int    check(t_stack **head)
{
    t_stack *it;

    it = *head;
    while(it != NULL)
    {
        if(it->keep == false)
            return (0);
        it = it->next;
    }
    return (1);
}

void count(t_stack **head, t_stk_inf *inf)
{
    t_stack *it;
    int      num;

    it = *inf->head_a;
    while (check(&it) == 0)
    {
        if(it->keep == true)
        {
           s_a(&it);
           great_than(&it); 
        }
        else if (it->keep == false)
        {
            p_b(&it, inf->head_b);
        }
        else
            r_a(&it);
        it = it->next;
    }
}
