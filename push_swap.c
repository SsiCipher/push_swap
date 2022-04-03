/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/03 05:44:29 by yanab            ###   ########.fr       */
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
	// t_stack	stack_b;
	t_node	*curr;
	int		size;

	init_stack(&stack_a, argc - 1, argv + 1);
	curr = stack_a.stack_top;
	size = stack_a.stack_size;
	while (curr && size--)
	{
		printf("item n'%d: [%d]\n", stack_a.stack_size - size, curr->content);
		curr = curr->next;
	}
	return (0);
}
