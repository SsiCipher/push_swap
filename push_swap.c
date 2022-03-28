/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/03/28 08:22:06 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(char *error)
{
	while (*error)
		write(2, error++, 1);
	exit(1);
}

int	is_stack_sorted(t_stack *stack_top)
{
	t_stack *curr;
	t_stack *next;

	curr = stack_top;
	next = stack_top->next;
	while (next != NULL)
	{
		if (curr->content > next->content)
			return (0);
		curr = curr->next;
		next = curr->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		args_count;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		print_err("Error: you have to provide a list of numbers\n");
	args = parse_args(argc - 1, (const char **)argv + 1, &args_count);
	if (args_count == 1)
		exit(0);
	init_stack(&stack_a, args_count, args);
	if (is_stack_sorted(stack_a))
		exit(0);
	index_stack(stack_a, args_count);

	print_stacks(stack_a, stack_b);
	sort_stack(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	return (0);
}
