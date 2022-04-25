/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:51:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/24 01:10:18 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2(t_stack *stack, int direction, char **ops)
{
	if (direction > 0)
	{
		if (stack->size >= 2)
		{
			if (stack->top->content > stack->top->next->content)
			{
				s(stack, ops == NULL, ops);
				return (1);
			}
		}
	}
	else
	{
		if (stack->size >= 2)
		{
			if (stack->top->content < stack->top->next->content)
			{
				s(stack, ops == NULL, ops);
				return (1);
			}
		}
	}
	return (0);
}

void	sort_3(t_stack *stack)
{
	int	arr[3];

	if (stack->size == 2)
		sort_2(stack, 1, NULL);
	else
	{
		arr[0] = stack->top->content;
		arr[1] = stack->top->next->content;
		arr[2] = stack->top->next->next->content;
		while (!is_stack_sorted(*stack))
		{
			if (arr[0] > arr[1] && arr[0] > arr[2])
				r(stack, TRUE, NULL);
			else if (arr[1] > arr[0] && arr[1] > arr[2])
				rr(stack, TRUE, NULL);
			else if (arr[0] > arr[1])
				s(stack, TRUE, NULL);
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
		min_index = stack_min(*stack_a, &min_value, &next_min_value);
		while (stack_a->top->content != min_value)
		{
			min_index = stack_min(*stack_a, &min_value, &next_min_value);
			if (stack_a->top->content == next_min_value && stack_b->size == 0)
				p(stack_b, stack_a, TRUE, NULL);
			else if (min_index <= stack_a->size / 2)
				r(stack_a, TRUE, NULL);
			else
				rr(stack_a, TRUE, NULL);
		}
		p(stack_b, stack_a, TRUE, NULL);
	}
	sort_3(stack_a);
	sort_2(stack_b, -1, NULL);
	while (stack_b->size > 0)
		p(stack_a, stack_b, TRUE, NULL);
}

void	sort_long(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int		size;
	int		chunk_size;
	int		range[2];
	char	*ops_str;

	ops_str = NULL;
	size = stack_a->size;
	set_chunk_size(size, &chunk_size);
	range[0] = size / 2 - chunk_size;
	range[1] = size / 2 + chunk_size;
	while (stack_a->size > 0)
	{
		while (stack_b->size < range[1] - range[0])
			a_to_b(stack_a, stack_b, range, &ops_str);
		expand_range(size, chunk_size, &range[0], &range[1]);
	}
	print_merged_ops(ops_str);
	free(ops_str);
	b_to_a(stack_a, stack_b, ref_array);
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
