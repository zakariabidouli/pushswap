# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 00:46:43 by zbidouli          #+#    #+#              #
#    Updated: 2022/12/25 01:23:35 by zbidouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT= ./libft/
LIBFT_BINARY = libft.a

M_SRCS 	= push_swap.c crack_a.c crack_b.c list_utils.c moves_down.c moves_list.c\
		moves_push.c moves_swap.c moves_up.c parse.c solve.c sort.c utils.c print_stacks.c\
		atoi.c b_to_a_utl.c cmd_list.c split.c split_utils.c simple_func.c

M_OBJS = $(M_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJS)
	@cd $(LIBFT) && make && cp ${LIBFT_BINARY} ../ 
	@$(CC) $(CFLAGS) ${LIBFT_BINARY} $^ -o $@
	@echo "DONE_PUSH_SWAP"

%.o : %.c pushswap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(M_OBJS) $(B_OBJS)
	@rm -rf $(LIBFT_BINARY)
	@cd $(LIBFT) && make clean
	@echo "DELETE_OBJ_FILES"

fclean: clean
	@rm -rf $(NAME)	
	@echo "DELETE_ALL"

re: fclean all

.PHONY: all clean fclean re
