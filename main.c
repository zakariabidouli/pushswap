#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack         *head_a;
    t_stack         *head_b;
    t_stack         *s;
    t_stack         *f;
    char            **tmp;
    int             *i = NULL;
    int             j;

    head_a = NULL;
    if (ac == 2)
    {
        tmp = ft_split(av[1], ' ', i);
        j = -1;
        while(tmp[++j])
           append(&head_a, ft_atoi(tmp[j]), j);
        append(&head_b, 1, 0);
        append(&head_b, 2, 1);
        append(&head_b, 3, 2);
        append(&head_b, 4, 3);
        append(&head_b, 5, 4);
        append(&head_b, 6, 5);

        // p_b(&head_a, &head_b);
        // r_r(&head_a, &head_b);
        s = head_a;
        f = head_b;
        while(s) 
        {
            printf("################ :%d", s->num);
            printf("################ :%d\n", f->num);
            printf("################ \n");
            printf("################ :%d", s->position);
            printf("################ :%d\n", f->position);
            printf("################ \n");

            s =  s->next;
            f =  f->next;
        }
    }
}