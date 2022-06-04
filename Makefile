.PHONY: all clean fclean re

NAME 	= pushswap

CC 		= gcc
FLAGS	= -Wall -Wextra -Werror


SRC 	 =  main.c utils.c

OBJS 		= $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	 $(NAME) $(OBJS) 

$(OBJS): $(SRC)
	 $(CC) $(FLAGS) -c $(SRC) 

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	rm -rf $(NAME)

re: fclean all

