/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/02/06 23:54:42 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(char *error)
{
	while (*error)
		write(2, error++, 1);
	exit(1);
}

int	cmp(int a, int b)
{
	return (a - b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*tmp_arr;
	char	**args;
	int		args_count;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		print_err("Error: you have to provide a list of numbers\n");
	args = parse_args(argc - 1, (const char **)argv + 1, &args_count);
	if (args_count == 1)
		exit(0);
	tmp_arr = init_stack(&stack_a, args_count, args);
	if (is_sorted(args_count, tmp_arr))
		exit(0);
	print_stacks(stack_a, stack_b);
	sort_stack(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	return (0);
}
