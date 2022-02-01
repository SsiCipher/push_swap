/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/02/01 21:56:09 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(int a, int b)
{
	return (a - b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*tmp_arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		print_err("Error: you have to provide a list of numbers\n");
	if (argc == 2)
		exit(0);
	tmp_arr = init_stack(&stack_a, argc - 1, argv + 1);
	if (is_sorted(argc - 1, tmp_arr))
		exit(0);
	// ft_qsort(tmp_arr, argc - 1, cmp);

	print_stack(stack_a, 'a');

	if (argc - 1 == 2 && tmp_arr[0] > tmp_arr[1])
		s(&stack_a, 'a');
	else if (argc - 1 == 3)
	{
		if (tmp_arr[1] < tmp_arr[0] && tmp_arr[1] < tmp_arr[2]  && tmp_arr[0] < tmp_arr[2])
		{
			s(&stack_a, 'a');
		}
		else if (tmp_arr[1] < tmp_arr[0] && tmp_arr[1] < tmp_arr[2] && tmp_arr[0] > tmp_arr[2])
		{
			r(&stack_a, 'a');
		}
	}

	print_stack(stack_a, 'a');

	// ----- TESTING ONLY
	// printf("---------------- PushSwap ----------------\n\n");
	// print_ops_count();
	// print_stack(stack_a, 'a');
	// print_stack(stack_b, 'b');
	// start_interactive_tester(stack_a, stack_b);
	// ----- TESTING ONLY
	return (0);
}
