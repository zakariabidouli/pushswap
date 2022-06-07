#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack         *head;
    t_stack         *s;
    char            **tmp;
    int             *i = NULL;
    int             j;

    head = NULL;
    if (ac == 2)
    {
        tmp = ft_split(av[1], ' ', i);
        j = -1;
        while(tmp[++j])
           append(&head, ft_atoi(tmp[j]), j);

        swap_a(&head);
        // s = head;
        // while(s)
        // {
        //     printf("################ :%d\n", s->num);
        //     printf("################ :%d\n", s->position);
        //     printf("################ \n");
        //     s =  s->next;
        }
    }
}