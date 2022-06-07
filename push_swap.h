
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"libft.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct s_stack{
    int                num;
    int                position;
    struct s_stack     *next;
    struct s_stack     *prev;
}t_stack;

char	    **ft_split(char const *s, char c, int *items_count);
void        append(t_stack **head_ref, int num, int position);
void         swap_a(t_stack  **head_ref);
void         swap_b(t_stack  **head_ref);



#endif