CC		=	cc
NAME	=	push_swap
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/stack.c src/stack_ops.c src/stack_utils.c \
			src/args_check.c src/sort.c src/test_utils.c \

LIBS	=	libft libgnl

all: libs $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C libs/$@
	@cp libs/$@/$@.a libs
	@echo "Done Creating > $@"

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(LIBS:%=libs/%.a) push_swap.c -o $(NAME)

clean:
	rm -rf $(NAME)
	rm -rf checker

fclean: clean
	make -C libs/libft fclean
	rm -rf libs/*.a

re: fclean all

bonus: all
	$(CC) $(FLAGS) $(SRCS) $(LIBS:%=libs/%.a) checker.c -o checker
