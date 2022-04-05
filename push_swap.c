/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/05 04:00:46 by yanab            ###   ########.fr       */
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

	// t_node *curr = stack_a.stack_top;
	// int size = stack_a.stack_size;
	// while (curr && size--)
	// {
	// 	printf("item n'%d: [%d]\n", stack_a.stack_size - size, curr->content);
	// 	curr = curr->next;
	// }

	printf("---------------- PushSwap ----------------\n");
	// print_ops_count();
	// p(&stack_b, &stack_a, TRUE, 'b');
	print_stacks(stack_a, stack_b);
	p(&stack_b, &stack_a, FALSE, 'b');
	printf("%d\n", stack_b.stack_top->content);
	print_stacks(stack_a, stack_b);

	// interactive_tester(&stack_a, &stack_b);

	return (0);
}
