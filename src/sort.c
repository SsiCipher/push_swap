/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/06 02:06:18 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	int	start;
	t_node *top = stack->stack_top;

	start = 1;
	while (stack->stack_top != top || start)
	{
		if (stack->stack_top > stack->stack_top->next)
			return (0);
		stack->stack_top = stack->stack_top->next;
	}
	return (1);
}

void	sort_3(t_stack *stack_a)
{
	int	arr[3];

	if (stack_a->stack_size <= 2)
	{
		if (stack_a->stack_top->content > stack_a->stack_top->next->content)
			s(stack_a, TRUE, 'a');
	}
	else
	{
		arr[0] = stack_a->stack_top->content;
		arr[1] = stack_a->stack_top->next->content;
		arr[2] = stack_a->stack_top->next->next->content;
		while (!is_stack_sorted(stack_a))
		{
			if (arr[0] > arr[1] && arr[0] > arr[2])
				r(stack_a, TRUE, 'a');
			else if (arr[1] > arr[0] && arr[1] > arr[2])
				rr(stack_a, TRUE, 'a');
			else if (arr[0] > arr[1])
				s(stack_a, TRUE, 'a');
			arr[0] = stack_a->stack_top->content;
			arr[1] = stack_a->stack_top->next->content;
			arr[2] = stack_a->stack_top->next->next->content;
		}
	}
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack_size <= 3)
		sort_3(stack_a);
}
