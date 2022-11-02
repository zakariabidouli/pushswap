NAME	= push_swap

CFLAGS 	= -Wall -Wextra -Werror

SRC_DIRS = srcs

SRC_FILES := $(foreach dirname, $(SRC_DIRS), $(wildcard $(dirname)/*.c))

OBJ_DIR = objs/

OBJS 	=$(SRC:*.c=.o)

PUSH_OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ))

HDR 		= -I./includes

LIBFT_HDR 	= -I./includes/libft

LIB_BINARY	= -L./includes/libft -lft

LIBFT		= ./includes/libft/libft.a

all: $(LIBFT) ./includes/libft/libft.a $(NAME)

FORCE:		;

# @echo Create: Object directory ${OBJS}
$(LIBFT):	FORCE
			make -C ./includes/libft

$(OBJ_DIR): $(SRC_FILES) $(LIBFT)
	mkdir -p $(OBJ_DIR) 
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@
	${PUSH_OBJ}

$(NAME):${OBJ_DIR} $(PUSH_OBJ) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJS) $(LIB_BINARY) -o $@
	@echo "##### push_swap compiling finished! #####"



clean:
	# /bin/rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./includes/libft fclean

re: fclean all

.PHONY: all clean fclean re