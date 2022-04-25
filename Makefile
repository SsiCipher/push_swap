CC		=	gcc
NAME	=	push_swap
BONUS_NAME	=	checker
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/init_data.c src/operations.c src/stack.c \
			src/stack_utils.c src/sort.c src/sort_utils.c \
			src/sort_utils2.c

INCS	= -I .

LIBS	=	libft libgnl

all: libs $(NAME)

$(NAME): $(SRCS) push_swap.c
	$(CC) $(FLAGS) $(INCS) $(SRCS) $(LIBS:%=libs/%.a) push_swap.c -o $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C libs/$@
	@cp libs/$@/$@.a libs
	@echo "Done Creating > $@"

clean:
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

fclean: clean
	make -C libs/libft fclean
	make -C libs/libgnl fclean
	rm -rf libs/*.a

re: fclean all

bonus: all $(BONUS_NAME)

$(BONUS_NAME): $(SRCS) checker.c
	$(CC) $(FLAGS) $(INCS) $(SRCS) $(LIBS:%=libs/%.a) checker.c -o $(BONUS_NAME)
