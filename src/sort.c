/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipher <cipher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:04:33 by yanab             #+#    #+#             */
/*   Updated: 2022/02/04 20:24:10 by cipher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(int length, int *arr)
{
	int	i;

	i = 0;
	while (++i < length)
	{
		if (arr[i] < arr[i - 1])
			return (0);
	}
	return (1);
}

int	get_stack_max(t_stack *stack_top, int *index)
{
	int	i;
	int	max;

	i = 0;
	max = stack_top->content;
	while (stack_top != NULL)
	{
		if (stack_top->content > max)
		{
			*index = i;
			max = stack_top->content;
		}
		i++;
		stack_top = stack_top->next;
	}
	return (max);
}

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

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_max;
	int	max_index;

	while ((*stack_a)->index > 3)
	{
		stack_a_max = get_stack_max(*stack_a, &max_index);
		while ((*stack_a)->content != stack_a_max)
		{
			if (max_index > (*stack_a)->index / 2)
				rr(stack_a, 'a');
			else
				r(stack_a, 'a');
		}
		p(stack_b, pop_stack(stack_a), 'b');
	}
	sort_3(stack_a);
	while (*stack_b != NULL)
	{
		p(stack_a, pop_stack(stack_b), 'a');
		r(stack_a, 'a');
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_size;

	stack_a_size = (*stack_a)->index;
	if (stack_a_size == 2 && (*stack_a)->content > (*stack_a)->next->content)
		s(stack_a, 'a');
	else if (stack_a_size == 3)
		sort_3(stack_a);
	else if (stack_a_size <= 5)
		sort_5(stack_a, stack_b);
}
