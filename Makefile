NAME	= push_swap

CFLAGS 	= -Wall -Wextra -Werror

SRC_DIRS = /srcs

UTILS = crack_a.c crack_b.c list_utils.c moves_down.c moves_list.c	\
		moves_push.c moves_swap.c moves_up.c parse.c solve.c		\
		sort.c utils.c


SRC_FILES = srcs/push_swap.c\
			$(UTILS:%.c=./src/%.c)

OBJ_DIR = objs/

OBJS 	= objs/push_swap.o\
			$(UTILS:%.c=./objs/%.o)

PUSH_OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ))

HDR 		= -I./includes

LIBFT_HDR 	= -I./includes/libft

LIB_BINARY	= -L./includes/libft -lft

LIBFT		= ./includes/libft/libft.a

all: $(LIBFT) ./includes/libft/libft.a $(NAME)

FORCE:		;

$(LIBFT):	FORCE
	@make -C ./includes/libft
	mkdir -p $(OBJ_DIR)
	@echo Create: Object directory ${OBJS}


$(OBJ_DIR)/%.o: $(SRC_FILES)/%.c $(LIBFT)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME):$(PUSH_OBJ) ${OBJS} $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJS) $(LIB_BINARY) -o $@
	@echo "##### push_swap compiling finished! #####"

clean:
	# /bin/rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./includes/libft fclean

re: fclean all

.PHONY: all clean fclean re