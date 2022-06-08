
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
void         push_front(t_stack ** head_ref, int num, int position);
void        deleteNode(t_stack ** head_ref, t_stack* del);
void         s_a(t_stack  **head_ref);
void         s_b(t_stack  **head_ref);
void         s_s(t_stack  **head_ref_a, t_stack  **head_ref_b);
void         r_a(t_stack  **head_ref);
void         r_b(t_stack  **head_ref);
void         r_r(t_stack  **head_ref_a, t_stack  **head_ref_b);
void         p_a(t_stack **head_ref_a,t_stack **head_ref_b);
void         p_b(t_stack **head_ref_a, t_stack  **head_ref_b);




#endif