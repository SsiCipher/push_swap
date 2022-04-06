/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/06 23:03:43 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_b.stack_size = 0;
	stack_b.stack_top = NULL;
	init_stack(&stack_a, argc - 1, argv + 1);
	if (stack_a.stack_size == 1 || is_stack_sorted(stack_a))
		exit(0);

	// print_stacks(stack_a, stack_b);
	sort_stacks(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b);

	// int	min_index;
	// int	min_value;
	// int	next_min_value;
	// min_index = stack_min(stack_a, &min_value, &next_min_value);
	// printf("Min: [%d], Index: [%d], Next Min: [%d]\n", min_value, min_index, next_min_value);

	return (0);
}
