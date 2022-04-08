/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/07 23:23:38 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	arr[3];

	if (stack->stack_size == 2)
	{
		if (stack->stack_top->content > stack->stack_top->next->content)
			s(stack, TRUE, 'a');
	}
	else
	{
		arr[0] = stack->stack_top->content;
		arr[1] = stack->stack_top->next->content;
		arr[2] = stack->stack_top->next->next->content;
		while (!is_stack_sorted(*stack))
		{
			if (arr[0] > arr[1] && arr[0] > arr[2])
				r(stack, TRUE, 'a');
			else if (arr[1] > arr[0] && arr[1] > arr[2])
				rr(stack, TRUE, 'a');
			else if (arr[0] > arr[1])
				s(stack, TRUE, 'a');
			arr[0] = stack->stack_top->content;
			arr[1] = stack->stack_top->next->content;
			arr[2] = stack->stack_top->next->next->content;
		}
	}
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	min_value;
	int	next_min_value;

	while (stack_a->stack_size > 3)
	{
		while (stack_a->stack_top->content != min_value)
		{
			min_index = stack_min(*stack_a, &min_value, &next_min_value) + 1;
			if (stack_a->stack_top->content == next_min_value
				&& stack_b->stack_size == 0)
				p(stack_b, stack_a, TRUE, 'b');
			else if (min_index <= stack_a->stack_size / 2)
				r(stack_a, TRUE, 'a');
			else
				rr(stack_a, TRUE, 'a');
		}
		p(stack_b, stack_a, TRUE, 'b');
	}
	sort_3(stack_a);
	if (stack_b->stack_size == 2)
	{
		if (stack_b->stack_top->content < stack_b->stack_top->next->content)
			s(stack_b, TRUE, 'b');
	}
	while (stack_b->stack_size > 0)
		p(stack_a, stack_b, TRUE, 'a');
}

void	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;

	(void)stack_a;
	(void)stack_b;
	chunk_size = stack_a->stack_size / 5;
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack_size <= 3)
		sort_3(stack_a);
	else if (stack_a->stack_size <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->stack_size <= 100)
		sort_100(stack_a, stack_b);
}
