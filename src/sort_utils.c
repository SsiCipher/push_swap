/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 05:54:07 by yanab             #+#    #+#             */
/*   Updated: 2022/04/16 05:55:18 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_chunk_size(int size, int *chunk_size)
{
	if (size <= 30)
		*chunk_size = size / 5;
	else if (size <= 100)
		*chunk_size = size / 8;
	else
		*chunk_size = size / 18;
}

void	expand_range(int size, int chunk_size, int *low, int *high)
{
	if (*low - chunk_size < 0)
		*low = 0;
	else
		*low -= chunk_size;
	if (*high + chunk_size > size)
		*high = size;
	else
		*high += chunk_size;
}
