/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/18 05:18:08 by yanab            ###   ########.fr       */
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
	int		*ref_array;

	stack_b.size = 0;
	stack_b.top = NULL;
	init_stack(&stack_a, argc - 1, argv + 1);
	if (stack_a.size == 1 || is_stack_sorted(stack_a))
		exit(0);
	ref_array = index_stack(stack_a);
	sort_stacks(&stack_a, &stack_b, ref_array);
	return (0);
}
