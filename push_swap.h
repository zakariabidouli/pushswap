
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include"libft.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef enum
{
	false,
	true,
}	t_bool;

typedef struct s_stack{
	int                num;
	int                index;
	t_bool             keep;
	struct s_stack     *next;
	struct s_stack     *prev;
}t_stack;

typedef struct s_stk_inf{
	t_stack **head_a;
	t_stack **head_b;
	int     size;
}t_stk_inf;

char	     **ft_split(char const *s, char c, int *items_count);
void         append(t_stack **head_ref, int num, int index);
void         push_front(t_stack ** head_ref, int num, int index);
void         deleteNode(t_stack ** head_ref, t_stack* del);
void         new_positions(t_stack  **head_ref);
void         s_a(t_stack  **head_ref);
void         s_b(t_stack  **head_ref);
void         s_s(t_stack  **head_ref_a, t_stack  **head_ref_b);
void         p_a(t_stack **head_ref_a,t_stack **head_ref_b);
void         p_b(t_stack **head_ref_a, t_stack  **head_ref_b);
void         r_a(t_stack  **head_ref);
void         r_b(t_stack  **head_ref);
void         r_r(t_stack  **head_ref_a, t_stack  **head_ref_b);
void         rr_a(t_stack  **head_ref);
void         rr_b(t_stack  **head_ref);
void         rr_r(t_stack  **head_ref_a, t_stack  **head_ref_b);
void         to_keep(t_stack **head_a, t_stk_inf *inf);
int          stacksize(t_stack **head_a);


#endif