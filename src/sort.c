/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/18 05:19:46 by yanab            ###   ########.fr       */
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

int	smart_rotate(t_stack *stack, int min, int max)
{
	int		start;
	int		end;
	t_node	*curr;

	start = 0;
	curr = stack->top;
	while (start < stack->size / 2)
	{
		if (curr->index >= min && curr->index < max)
			break ;
		curr = curr->next;
		start++;
	}
	end = 0;
	curr = stack->top->prev;
	while (end < stack->size / 2)
	{
		if (curr->index >= min && curr->index < max)
			break ;
		curr = curr->prev;
		end++;
	}
	return (start - end);
}

void	sort_long(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int		size;
	int		sr;
	int		chunk_size;
	int		range_low;
	int		range_high;
	char	*ops_str;

	ops_str = NULL;
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
				p(stack_b, stack_a, FALSE, 'b');
				concat_op(&ops_str, "pb\n");
				if (stack_b->top->index < size / 2)
				{
					r(stack_b, FALSE, 'b');
					concat_op(&ops_str, "rb\n");
				}
			}
			else
			{
				sr = smart_rotate(stack_a, range_low, range_high);
				while (
					stack_a->top->index < range_low
					|| stack_a->top->index >= range_high
				)
				{
					if (sr <= 0)
					{
						r(stack_a, FALSE, 'a');
						concat_op(&ops_str, "ra\n");
					}
					else
					{
						rr(stack_a, FALSE, 'a');
						concat_op(&ops_str, "rra\n");
					}
				}
			}
		}
		expand_range(size, chunk_size, &range_low, &range_high);
	}
	print_merged_ops(ops_str);
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
