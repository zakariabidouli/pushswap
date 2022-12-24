# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 00:46:43 by zbidouli          #+#    #+#              #
#    Updated: 2022/12/24 00:46:44 by zbidouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

LIBFT_BINARY = libft.a

M_SRCS 	= push_swap.c crack_a.c crack_b.c list_utils.c moves_down.c moves_list.c\
		moves_push.c moves_swap.c moves_up.c parse.c solve.c sort.c utils.c print_stacks.c

M_OBJS = $(M_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJS)
	@$(CC) $(CFLAGS) ${LIBFT_BINARY} $^ -o $@
	@echo "DONE_PUSH_SWAP"

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(M_OBJS) $(B_OBJS)
	@echo "DELETE_OBJ_FILES"

fclean: clean
	@rm -rf $(NAME) $(bonus) 
	@echo "DELETE_ALL"

re: fclean all

.PHONY: all clean fclean re
