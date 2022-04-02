/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/02 05:43:38 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	parse_args(int argc, char **argv, int *new_argc, char ***new_argv)
{
	int		i;
	char	*temp;
	char	*joined_args;

	i = -1;
	joined_args = NULL;
	while (++i < argc)
	{
		temp = joined_args;
		joined_args = ft_strjoin(joined_args, argv[i]);
		free(temp);
		temp = joined_args;
		joined_args = ft_strjoin(joined_args, " ");
		free(temp);
	}
	*new_argv = ft_split(joined_args, ' ');
	free(joined_args);
	i = -1;
	while ((*new_argv)[++i])
		*new_argc += 1;
}

bool	contains_dups(int argc, char **argv)
{
	int	i;

	while (--argc)
	{
		i = -1;
		while (++i < argc)
		{
			if (!ft_strcmp(argv[argc], argv[i]))
				return (TRUE);
		}
	}
	return (FALSE);
}

int	atoi_check(char *number)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	if (number[i] == '-' || number[i] == '+')
		if (number[i++] == '-')
			sign *= -1;
	num = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			print_error("Error: the arguments contain a non integer");
		num = num * 10 + (number[i++] - '0');
	}
	if (sign * num <= INT_MIN || sign * num >= INT_MAX)
		print_error("Error: the arguments are out of integer range");
	return (sign * num);
}

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int		n;
	int		new_argc;
	char	**new_argv;
	t_node	*new_node;

	(void)stack;
	new_argc = 0;
	new_argv = NULL;
	parse_args(argc, argv, &new_argc, &new_argv);

	if (contains_dups(new_argc, new_argv))
		print_error("Error:\nThe arguments contain duplicates");
	while (new_argc--)
	{
		n = atoi_check(new_argv[new_argc]);
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			print_error("Error:\nfailed to allocate memory");
		new_node->content = n;
		new_node->next = NULL;
		// push to stack
	}
}

int main(int argc, char **argv)
{
	t_stack stack_a;
	// t_stack stack_b;

	// parse args & init stacks
	init_stack(&stack_a, argc - 1, argv + 1);

	// index stack
	// sort stack

	return (0);
}
