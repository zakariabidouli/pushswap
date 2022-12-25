/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:47:27 by zbidouli          #+#    #+#             */
/*   Updated: 2022/12/25 01:26:00 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define FT_INT_MAX 2147483647
#define FT_INT_MIN -2147483648
#define COL "\033[0;31m"
#define RESET_COL "\033[0m"

typedef enum
{
	false,
	true,
} t_bool;

typedef enum
{
	Rot,
	RevRot,
} t_direction;

typedef struct s_stack
{
	int				num;
	ssize_t			index;
	t_bool			keep;
	struct s_stack	*next;
	struct s_stack	*prev;
} t_stack;

typedef struct s_stk
{
	t_stack	*head;
	t_stack	*markup_head;
	size_t	size;
	size_t	pairs;
} t_stk;

typedef struct s_moves
{
	char			*name;
	struct s_moves	*next;
} t_moves;

typedef struct s_moves_list
{
	t_moves	*head;
	size_t	size;
} t_moves_list;

typedef struct s_flag
{
	t_stack		*flag_a;
	t_stack		*flag_b;
	t_direction	a_moves;
	t_direction	b_moves;
	size_t		size;
	t_bool		is_done;
} t_flag;

char			**ft_split(char const *s, char c, int *items_count);
void			append(t_stk *stack, int num);
void			push_front(t_stack *head_ref, int num, int index);
void			new_positions(t_stack **head_ref);
void			s_a(t_stk *stack);
void			s_x_l(t_stk *stack, t_moves_list *list);
void			s_b(t_stk *stack);
void			s_s(t_stk *stack_a, t_stk *stack_b);
void			p_b_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list);
void			p_a_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list);
void			r_a(t_stk *stack);
void			r_b(t_stk *stack);
void			r_r(t_stk *stack_a, t_stk *stack_b);
void			r_a_l(t_stk *stack, t_moves_list *list);
void			r_b_l(t_stk *stack, t_moves_list *list);
void			rr_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list);
void			rr_a(t_stk *stack);
void			rr_b(t_stk *stack);
void			rr_r(t_stk *stack_a, t_stk *stack_b);
void			rr_a_l(t_stk *stack, t_moves_list *list);
void			rr_b_l(t_stk *stack, t_moves_list *list);
void			rr_r_l(t_stk *stack_a, t_stk *stack_b, t_moves_list *list);
size_t			sort_greater(t_stk *stack, t_stack *markup_head);
size_t			sort_index(t_stk *stack, t_stack *markup_head);
void			to_keep(t_stk	*stack, size_t (*markup)(t_stk *, t_stack *));
int				stacksize(t_stack	**head_a);
t_bool			is_int(const char	*number, t_bool	strict);
t_bool			is_num(char	*str);
void			terminated(char const	*s);
t_moves_list	*init_moves(void);
t_stk			*init_stack(void);
t_stk			*parse(int	ac, char	**av);
void			duplicated(t_stk	*stack);
void			crack_b(t_stk	*stack_a, t_stk	*stack_b,
						t_moves_list	*command_list);
void			crack_a(t_stk	*stack_a, t_stk	*stack_b,
						size_t	(markup)(t_stk *stack, t_stack *markup_head),
						t_moves_list *command_list);
t_moves_list	*solve(t_stk *stack_a, size_t(markup)(t_stk *stack, t_stack *markup_head));
void			free_stack(t_stk *stack);
void			add_command(t_moves_list *list, t_moves *command);
t_moves			*create_command(const char	*name);
void			split_free(char	***strsplit);
int				max(int	x, int	y);
int				my_abs(int	x);
void			print_stacks(t_stk	*a_stack, t_stk	*b_stack, t_bool	color);
long			ft_atoi(const char	*str);
void			cal(t_stk *stack_a, t_stk *stack_b, t_stack *b, t_flag	*info);
t_flag			*init_flag(void);
void			*ft_memalloc(size_t size);
void			free_c(t_moves_list *list);
void			print_c(t_moves_list *list);
int				str_len(char *s);
int				ft_isspace(int c);
#endif
