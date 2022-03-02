/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:04:33 by yanab             #+#    #+#             */
/*   Updated: 2022/02/28 06:16:23 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int	arr[3];

	arr[0] = (*stack_a)->content;
	arr[1] = (*stack_a)->next->content;
	arr[2] = (*stack_a)->next->next->content;
	while (!is_sorted(3, arr))
	{
		if (arr[0] > arr[1] && arr[0] > arr[2])
			r(stack_a, 'a');
		else if (arr[1] > arr[0] && arr[1] > arr[2])
			rr(stack_a, 'a');
		else if (arr[0] > arr[1])
			s(stack_a, 'a');
		arr[0] = (*stack_a)->content;
		arr[1] = (*stack_a)->next->content;
		arr[2] = (*stack_a)->next->next->content;
	}
}

void	sort_5_max(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_max;
	int	stack_a_next_max;
	int	max_index;

	while ((*stack_a)->index > 3)
	{
		stack_a_max = get_stack_max(*stack_a, &max_index, &stack_a_next_max);
		while ((*stack_a)->content != stack_a_max)
		{
			if (max_index > (*stack_a)->index / 2)
				rr(stack_a, 'a');
			else
				r(stack_a, 'a');
		}
		p(stack_b, stack_pop(stack_a), 'b');
	}
	sort_3(stack_a);
	while (*stack_b != NULL)
	{
		p(stack_a, stack_pop(stack_b), 'a');
		r(stack_a, 'a');
	}
}

void	sort_5_min(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_min;
	int	stack_a_next_min;
	int	min_index;
	int	is_lt_5;

	is_lt_5 = (*stack_a)->index < 5;
	while ((*stack_a)->index > 3)
	{
		stack_a_min = get_stack_min(*stack_a, &min_index, &stack_a_next_min);
		while ((*stack_a)->content != stack_a_min)
		{
			if ((*stack_a)->content == stack_a_next_min && !is_lt_5)
				p(stack_b, stack_pop(stack_a), 'b');
			else
			{
				if (min_index > (*stack_a)->index / 2)
					rr(stack_a, 'a');
				else
					r(stack_a, 'a');
			}
		}
		p(stack_b, stack_pop(stack_a), 'b');
	}
	sort_3(stack_a);
	if ((*stack_b)->index == 2)
		if ((*stack_b)->content < (*stack_b)->next->content)
			s(stack_b, 'b');
	while (*stack_b != NULL)
		p(stack_a, stack_pop(stack_b), 'a');
}

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int stack_a_size;

	(void)stack_b;
	stack_a_size = (*stack_a)->index;
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_size;

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
