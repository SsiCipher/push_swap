/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:06:04 by yanab             #+#    #+#             */
/*   Updated: 2022/04/23 00:49:40 by yanab            ###   ########.fr       */
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

void	push_(t_stack *stacks[2], int *ref, int *max_index, int *down_c)
{
	if (stacks[1]->top->content == ref[*max_index])
	{
		p(stacks[0], stacks[1], TRUE, NULL);
		*max_index -= 1;
		if (sort_2(stacks[0], 1))
			*max_index -= 1;
	}
	else if (stacks[1]->top->content == ref[*max_index - 1])
		p(stacks[0], stacks[1], TRUE, NULL);
	else
	{
		if (*down_c == 0 && stacks[1]->top->content < stack_tail(*stacks[0]))
		{
			p(stacks[0], stacks[1], TRUE, NULL);
			r(stacks[0], TRUE, NULL);
			*down_c += 1;
		}
		else
		{
			if (get_index(*stacks[1], ref[*max_index]) <= stacks[1]->size / 2)
				r(stacks[1], TRUE, NULL);
			else
				rr(stacks[1], TRUE, NULL);
		}
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int		down_c;
	int		max_index;
	int		max_stack_index;
	t_stack	*stacks[2];

	down_c = 0;
	max_index = stack_b->size - 1;
	stacks[0] = stack_a;
	stacks[1] = stack_b;
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
			push_(stacks, ref_array, &max_index, &down_c);
	}
	while (down_c-- > 0)
		rr(stack_a, TRUE, NULL);
}
