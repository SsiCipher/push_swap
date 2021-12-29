/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2021/12/29 20:39:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*tmp_arr;

	stack_a = NULL;
	stack_b = NULL;
	printf("---------------- PushSwap ----------------\n\n");
	if (argc <= 1)
		print_err("Error: you have to provide a list of numbers\n");
	tmp_arr = init_stack(&stack_a, argc - 1, argv + 1);
	if (is_sorted(argc - 1, tmp_arr))
		print_err("The arguments are already sorted\n");
	print_ops_count();
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	start_interactive_tester(stack_a, stack_b);
	return (0);
}
