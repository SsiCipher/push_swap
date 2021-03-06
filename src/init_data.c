/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:37:31 by yanab             #+#    #+#             */
/*   Updated: 2022/04/26 02:00:27 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int argc, char **argv, char ***new_argv)
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
		if (!joined_args)
			print_error("Error:\nfailed to allocate memory");
		free(temp);
	}
	*new_argv = ft_split(joined_args, ' ');
	if (!(*new_argv))
		print_error("Error:\nfailed to allocate memory");
	free(joined_args);
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
	{
		if (number[i++] == '-')
			sign *= -1;
		if (number[i] < '0' || number[i] > '9')
			print_error("Error:\nthe arguments contain a non integer");
	}
	num = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			print_error("Error:\nthe arguments contain a non integer");
		num = num * 10 + (number[i++] - '0');
	}
	if (sign * num <= INT_MIN || sign * num >= INT_MAX)
		print_error("Error:\nthe arguments are out of integer range");
	return (sign * num);
}

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		new_argc;
	char	**new_argv;
	t_node	*new_node;

	new_argc = 0;
	new_argv = NULL;
	parse_args(argc, argv, &new_argv);
	i = -1;
	while (new_argv[++i])
		new_argc += 1;
	if (new_argc == 0)
		exit(EXIT_SUCCESS);
	if (contains_dups(new_argc, new_argv))
		print_error("Error:\nThe arguments contain duplicates");
	while (new_argc--)
	{
		new_node = create_node(atoi_check(new_argv[new_argc]));
		if (!new_node)
			print_error("Error:\nfailed to allocate memory");
		stack_push(stack, new_node);
		free(new_argv[new_argc]);
	}
	free(new_argv);
}

int	*index_stack(t_stack stack)
{
	int		i;
	int		*stack_arr;
	t_node	*curr;

	i = -1;
	curr = stack.top;
	stack_arr = (int *)malloc(sizeof(int) * stack.size);
	while (++i < stack.size)
	{
		stack_arr[i] = curr->content;
		curr = curr->next;
	}
	ft_qsort(stack_arr, stack.size, NULL);
	i = -1;
	curr = stack.top;
	while (++i < stack.size)
	{
		curr->index = ft_find(stack.size, stack_arr, curr->content);
		curr = curr->next;
	}
	return (stack_arr);
}
