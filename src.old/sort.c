/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:04:33 by yanab             #+#    #+#             */
/*   Updated: 2022/04/11 02:42:38 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void lift_to_top(t_stack **stack_b, int value, int index, int stack_size)
{
	if (index == stack_size)
		return;
	else if (index == stack_size - 1)
		s(stack_b, 'b');
	else
	{
		while ((*stack_b)->content != value)
		{
			if (index > stack_size / 2)
				rr(stack_b, 'b');
			else
				r(stack_b, 'b');
		}
	}
}

int get_max_index(t_stack *stack, int *max)
{
	*max = stack->content;
	int max_i = stack->index;
	for (t_stack *curr = stack; curr; curr = curr->next)
	{
		if (curr->content > *max)
		{
			*max = curr->content;
			max_i = curr->index;
		}
	}
	return (max_i);
}

int get_min_index(t_stack *stack, int *min)
{
	*min = stack->content;
	int min_i = stack->index;
	for (t_stack *curr = stack; curr; curr = curr->next)
	{
		if (curr->content < *min)
		{
			*min = curr->content;
			min_i = curr->index;
		}
	}
	return (min_i);
}

void sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int stack_a_size;
	int chunk_size;
	int val;

	stack_a_size = (*stack_a)->index;
	chunk_size = stack_a_size / 10;

	for (int i = 1; i * chunk_size <= stack_a_size; i++)
	{
		int j = 0;
		while (j < i * chunk_size && *stack_a != NULL)
		{
			if ((*stack_a)->order_index < chunk_size * i)
			{
				p(stack_b, stack_pop(stack_a), 'b');
				j++;
			}
			else
			{
				int max_i = get_min_index(*stack_a, &val);
				lift_to_top(stack_a, val, max_i, (*stack_a)->index);
				p(stack_b, stack_pop(stack_a), 'b');
			}
		}
	}

	while (*stack_b != NULL)
	{
		int val;
		int max_i = get_max_index(*stack_b, &val);
		lift_to_top(stack_b, val, max_i, (*stack_b)->index);
		p(stack_a, stack_pop(stack_b), 'a');
	}
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int stack_a_size;

	stack_a_size = (*stack_a)->index;
	if (stack_a_size <= 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			s(stack_a, 'a');
	}
	else if (stack_a_size == 3)
		sort_3(stack_a);
	else if (stack_a_size <= 5)
		sort_5_min(stack_a, stack_b);
	else if (stack_a_size <= 100)
		sort_100(stack_a, stack_b);
}
