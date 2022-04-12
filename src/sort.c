/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/12 03:41:05 by yanab            ###   ########.fr       */
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
			if (stack_a->stack_top->content == next_min_value && stack_b->stack_size == 0)
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

void	smart_rotate(t_stack *stack, int max)
{
	int start;
	int end;
	t_node *curr;

	start = 0;
	curr = stack->stack_top;
	while (start < stack->stack_size / 2)
	{
		if (curr->index < max)
			break ;
		curr = curr->next;
		start++;
	}
	end = 0;
	curr = stack->stack_top->prev;
	while (end < stack->stack_size / 2)
	{
		if (curr->index < max)
			break ;
		curr = curr->prev;
		end++;
	}
	while (stack->stack_top->index >= max)
	{
		if (start < end)
			r(stack, TRUE, 'a');
		else
			rr(stack, TRUE, 'a');
	}
}

// 700: 5pts
// 1500: 1pts

// void	sort_100(t_stack *stack_a, t_stack *stack_b)
// {
// 	int pushed = 0;
// 	int chunk_i = 1;
// 	int chunk_size = stack_a->stack_size / 5;
// 	while (stack_a->stack_size > 0)
// 	{
// 		if (stack_a->stack_size == 1)
// 			break ;
// 		pushed = 0;
// 		while (pushed < chunk_size)
// 		{
// 			if (stack_a->stack_size == 1)
// 				break ;
// 			if (stack_a->stack_top->index < chunk_size * chunk_i)
// 			{
// 				p(stack_b, stack_a, TRUE, 'b');
// 				pushed += 1;
// 			}
// 			else
// 				smart_rotate(stack_a, chunk_size * chunk_i);
// 		}
// 		chunk_i += 1;
// 	}
// }

void	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	int pushed = 0;
	int chunk_i = 1;
	int chunk_size = stack_a->stack_size / 5;
	int size = stack_a->stack_size;
	int range_low;
	int range_high;

	while (stack_a->stack_size > 0)
	{
		printf("stack size %d\n", stack_a->stack_size);
		pushed = 0;
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

		printf(
			"range: [%d, %d]\n",
			range_low,
			range_high
		);

		while (pushed < chunk_size * 2)
		{
			if (
				stack_a->stack_top->index >= range_low
				&& stack_a->stack_top->index < range_high
			)
			{
				if (stack_a->stack_top->index < size / 2)
				{
					p(stack_b, stack_a, TRUE, 'b');
					r(stack_b, TRUE, 'b');
				}
				else
					p(stack_b, stack_a, TRUE, 'b');
				pushed += 1;
			}
			else
				r(stack_a, TRUE, 'a');
		}
		chunk_i += 1;
	}
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
