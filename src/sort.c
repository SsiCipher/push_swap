/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/16 05:54:21 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	arr[3];

	if (stack->size == 2)
	{
		if (stack->top->content > stack->top->next->content)
			s(stack, TRUE, 'a');
	}
	else
	{
		arr[0] = stack->top->content;
		arr[1] = stack->top->next->content;
		arr[2] = stack->top->next->next->content;
		while (!is_stack_sorted(*stack))
		{
			if (arr[0] > arr[1] && arr[0] > arr[2])
				r(stack, TRUE, 'a');
			else if (arr[1] > arr[0] && arr[1] > arr[2])
				rr(stack, TRUE, 'a');
			else if (arr[0] > arr[1])
				s(stack, TRUE, 'a');
			arr[0] = stack->top->content;
			arr[1] = stack->top->next->content;
			arr[2] = stack->top->next->next->content;
		}
	}
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	min_value;
	int	next_min_value;

	while (stack_a->size > 3)
	{
		while (stack_a->top->content != min_value)
		{
			min_index = stack_min(*stack_a, &min_value, &next_min_value) + 1;
			if (stack_a->top->content == next_min_value && stack_b->size == 0)
				p(stack_b, stack_a, TRUE, 'b');
			else if (min_index <= stack_a->size / 2)
				r(stack_a, TRUE, 'a');
			else
				rr(stack_a, TRUE, 'a');
		}
		p(stack_b, stack_a, TRUE, 'b');
	}
	sort_3(stack_a);
	if (stack_b->size == 2)
	{
		if (stack_b->top->content < stack_b->top->next->content)
			s(stack_b, TRUE, 'b');
	}
	while (stack_b->size > 0)
		p(stack_a, stack_b, TRUE, 'a');
}

void	sort_long(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int	size;
	int	chunk_size;
	int	range_low;
	int	range_high;

	size = stack_a->size;
	set_chunk_size(size, &chunk_size);
	range_low = size / 2 - chunk_size;
	range_high = size / 2 + chunk_size;
	while (stack_a->size > 0)
	{
		while (stack_b->size < range_high - range_low)
		{
			if (
				stack_a->top->index >= range_low
				&& stack_a->top->index < range_high
			)
			{
				p(stack_b, stack_a, TRUE, 'b');
				if (stack_b->top->index < size / 2)
					r(stack_b, TRUE, 'b');
			}
			else
				smart_rotate(stack_a, 'a', range_low, range_high);
		}
		expand_range(size, chunk_size, &range_low, &range_high);
	}
	sort_push_b(stack_a, stack_b, ref_array);
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	if (stack_a->size <= 3)
		sort_3(stack_a);
	else if (stack_a->size <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->size <= 500)
		sort_long(stack_a, stack_b, ref_array);
}
