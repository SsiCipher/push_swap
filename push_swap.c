/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/02 05:28:55 by yanab            ###   ########.fr       */
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
		while (i < argc)
		{
			if (ft_strcmp(argv[argc], argv[i]) == 0)
				return (TRUE);
		}
	}
	return (FALSE);
}

void	init_stack(t_node **stack_top, int argc, char **argv)
{
	int		i;
	int		new_argc;
	char	**new_argv;

	(void)stack_top;
	new_argc = 0;
	new_argv = NULL;
	parse_args(argc, argv, &new_argc, &new_argv);
	if (contains_dups(new_argc, new_argv))
		print_error("Error:\nThe arguments contain duplicates");
	// check stack for duplicates
	// check stack for non-integers
	// check stack for out of INT range	
}

int main(int argc, char **argv)
{
	t_stack stack_a;
	// t_stack stack_b;

	// parse args & init stacks
	init_stack(&(stack_a.stack_top), argc - 1, argv + 1);

	// index stack
	// sort stack

	return (0);
}
