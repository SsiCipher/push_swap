/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:06:04 by yanab             #+#    #+#             */
/*   Updated: 2022/04/22 05:53:13 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack_a, t_stack *stack_b, int range[2], char **ops)
{
	int	middle;

	middle = range[1] - (range[1] - range[0]) / 2;
	if (ft_inrange(stack_a->top->index, range[0], range[1]))
	{
		p(stack_b, stack_a, FALSE, ops);
		if (stack_b->top->index < middle)
			r(stack_b, FALSE, ops);
	}
	else
	{
		while (!ft_inrange(stack_a->top->index, range[0], range[1]))
		{
			if (smart_rotate(stack_a, range[0], range[1]) <= 0)
				r(stack_a, FALSE, ops);
			else
				rr(stack_a, FALSE, ops);
		}
	}
}

void	push_(t_stack *stack_a, t_stack *stack_b, int *ref_array, int *max_index, int *down_c)
{
	if (stack_b->top->content == ref_array[*max_index])
	{
		p(stack_a, stack_b, TRUE, NULL);
		*max_index -= 1;
		if (sort_2(stack_a, 1))
			*max_index -= 1;
	}
	else if (stack_b->top->content == ref_array[*max_index - 1])
		p(stack_a, stack_b, TRUE, NULL);
	else
	{
		if (*down_c == 0 && stack_b->top->content < stack_tail(*stack_a))
		{
			p(stack_a, stack_b, TRUE, NULL);
			r(stack_a, TRUE, NULL);
			*down_c += 1;
		}
		else
		{
			if (get_index(*stack_b, ref_array[*max_index]) <= stack_b->size / 2)
				r(stack_b, TRUE, NULL);
			else
				rr(stack_b, TRUE, NULL);
		}
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int	down_c;
	int	max_index;
	int	max_stack_index;

	down_c = 0;
	max_index = stack_b->size - 1;
	while (stack_b->size > 0)
	{
		max_stack_index = get_index(*stack_b, ref_array[max_index]);
		if (max_stack_index == -1)
		{
			rr(stack_a, TRUE, NULL);
			down_c -= 1;
			max_index -= 1;
		}
		else
			push_(stack_a, stack_b, ref_array, &max_index, &down_c);
	}
	while (down_c-- > 0)
		rr(stack_a, TRUE, NULL);
}
