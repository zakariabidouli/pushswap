.PHONY: all clean fclean re

NAME 	= pushswap

CC 		= gcc
FLAGS	= -Wall -Wextra -Werror


SRC 	 =  main.c utils.c list_utils.c moves_swap.c \
			moves_push.c

OBJS 		= $(SRC:%.c=%.o)
	 
all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(FLAGS)  $(SRC) libft.a -o ${NAME} 

$(OBJS): $(SRC)
	 $(CC) $(FLAGS)  -c  $(SRC) 

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME)

re: fclean all
