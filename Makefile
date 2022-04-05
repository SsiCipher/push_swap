CC		=	cc
NAME	=	push_swap
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/init_data.c src/operations.c src/stack.c \
			src/stack_utils.c src/test_utils.c

INCS	= -I .

LIBS	=	libft libgnl

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
	make -C libs/libgnl fclean
	rm -rf libs/*.a

re: fclean all
