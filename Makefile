CC		=	gcc
NAME	=	push_swap
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	src/stack.c  src/operations.c  src/sort.c  src/check.c \
			src/test_utils.c  push_swap.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
