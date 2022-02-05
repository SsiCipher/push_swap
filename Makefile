CC		=	gcc
NAME	=	push_swap
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/stack.c src/operations.c src/sort.c src/check.c \
			src/test_utils.c push_swap.c

LIBS	=	libft

all: libs $(NAME)

libs: $(LIBS)

$(LIBS):
	@make -C libs/$@
	@cp libs/$@/$@.a libs
	@echo "Done Creating > $@"

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(LIBS:%=libs/%.a) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	make -C libs/libft fclean
	rm -rf libs/libft.a

re: fclean all
