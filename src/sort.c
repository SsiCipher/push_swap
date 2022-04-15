/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/15 05:36:38 by yanab            ###   ########.fr       */
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

// < 700  : 5pts
// < 900  : 4pts
// < 1500 : 1pts

void	smart_rotate(t_stack *stack, char stack_name, int min, int max)
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
	while (stack->top->index < min || stack->top->index >= max)
	{
		if (start < end)
			r(stack, TRUE, stack_name);
		else
			rr(stack, TRUE, stack_name);
	}
}

void	sort_push_b(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int	max_value;
	int	max_value_index;
	int	next_max_value;

	while (stack_b->size > 0)
	{
		max_value = ref_array[stack_b->size - 1];
		max_value_index = get_index(*stack_b, max_value);
		next_max_value = ref_array[stack_b->size - 2];
		while (stack_b->top->content != max_value)
		{
			if (stack_b->top->content == next_max_value)
				p(stack_a, stack_b, TRUE, 'a');
			else
			{
				if (max_value_index <= stack_b->size / 2)
					r(stack_b, TRUE, 'b');
				else
					rr(stack_b, TRUE, 'b');
			}
		}
		p(stack_a, stack_b, TRUE, 'a');
		if (stack_a->size >= 2)
		{
			if (stack_a->top->content > stack_a->top->next->content)
				s(stack_a, TRUE, 'a');
		}
	}
}

void	sort_100(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int	chunk_i;
	int	chunk_size;
	int	size;
	int	range_low;
	int	range_high;

	if (size <= 30)
		chunk_size = size / 10;
	else if (size <= 100)
		chunk_size = size / 20;
	else
		chunk_size = size / 25;
	size = stack_a->size;
	chunk_i = 0;
	while (stack_a->size > 0)
	{
		if (
			size / 2 - chunk_size * chunk_i < 0
			|| size / 2 + chunk_size * chunk_i > size
		)
		{
			range_low = 0;
			range_high = size;
		}
		else
		{
			range_low = size / 2 - chunk_size * chunk_i;
			range_high = size / 2 + chunk_size * chunk_i;
		}
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
		chunk_i += 1;
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
		sort_100(stack_a, stack_b, ref_array);
}
