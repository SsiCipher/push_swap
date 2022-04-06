/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/06 05:29:30 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	is_stack_sorted(t_stack stack)
{
	int		start;
	t_node	*top;

	start = 1;
	top = stack.stack_top;
	while (stack.stack_top != top || start)
	{
		if (stack.stack_top->content > stack.stack_top->next->content)
			return (0);
		stack.stack_top = stack.stack_top->next;
		start = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_b.stack_size = 0;
	stack_b.stack_top = NULL;
	init_stack(&stack_a, argc - 1, argv + 1);

	print_stacks(stack_a, stack_b);
	// sort_stacks(&stack_a, &stack_b);
	printf("stack sorted: [%d]\n", is_stack_sorted(stack_a));

	return (0);
}
