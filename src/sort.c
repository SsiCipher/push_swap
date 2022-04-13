/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/13 05:57:50 by yanab            ###   ########.fr       */
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

void	smart_rotate(t_stack *stack, int max)
{
	int		start;
	int		end;
	t_node	*curr;

	start = 0;
	curr = stack->top;
	while (start < stack->size / 2)
	{
		if (curr->index < max)
			break;
		curr = curr->next;
		start++;
	}
	end = 0;
	curr = stack->top->prev;
	while (end < stack->size / 2)
	{
		if (curr->index < max)
			break;
		curr = curr->prev;
		end++;
	}
	while (stack->top->index >= max)
	{
		if (start < end)
			r(stack, TRUE, 'a');
		else
			rr(stack, TRUE, 'a');
	}
}

// 700: 5pts
// 1500: 1pts

void	sort_push_b(t_stack *stack_a, t_stack *stack_b)
{
	int rot_counter;
	int max_value;

	while (stack_b->size > 0)
	{
		rot_counter = 0;

		stack_max(*stack_b, &max_value);

		while (stack_b->top->content != max_value)
		{
			r(stack_b, TRUE, 'b');
			rot_counter++;
		}
		
		p(stack_a, stack_b, TRUE, 'a');

		while (rot_counter > 0)
		{
			rr(stack_b, TRUE, 'b');
			rot_counter--;
		}
	}
}

void	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_i = 1;
	int	chunk_size = stack_a->size / 20;
	int	size = stack_a->size;
	int	range_low;
	int	range_high;

	while (stack_a->size > 0)
	{
		if (
			size / 2 - chunk_size * chunk_i < 0 || size / 2 + chunk_size * chunk_i > size)
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
				stack_a->top->index >= range_low && stack_a->top->index < range_high)
			{
				if (stack_a->top->index < size / 2)
				{
					p(stack_b, stack_a, TRUE, 'b');
					r(stack_b, TRUE, 'b');
				}
				else
					p(stack_b, stack_a, TRUE, 'b');
			}
			else
				r(stack_a, TRUE, 'a');
		}
		
		chunk_i += 1;
	}

	sort_push_b(stack_a, stack_b);
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		sort_3(stack_a);
	else if (stack_a->size <= 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->size <= 500)
		sort_100(stack_a, stack_b);
}
