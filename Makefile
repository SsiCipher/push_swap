CC		=	gcc
NAME	=	push_swap
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/init_data.c src/operations.c src/stack.c \
			src/stack_utils.c src/test_utils.c src/sort.c

INCS	= -I .

LIBS	=	libft

all: libs $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C libs/$@
	@cp libs/$@/$@.a libs
	@echo "Done Creating > $@"

$(NAME): $(SRCS) push_swap.c
	$(CC) $(FLAGS) $(INCS) $(SRCS) $(LIBS:%=libs/%.a) push_swap.c -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	make -C libs/libft fclean
	rm -rf libs/*.a

re: fclean all
