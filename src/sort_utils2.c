/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:06:04 by yanab             #+#    #+#             */
/*   Updated: 2022/04/25 01:08:47 by yanab            ###   ########.fr       */
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
			r(stack_a, FALSE, ops);
	}
}

int	push_max(t_stack *stack_a, t_stack *stack_b, int *ref, t_vars *vars)
{
	if (stack_b->top->content == ref[vars->max_index])
	{
		p(stack_a, stack_b, FALSE, &(vars->ops_str));
		vars->max_index -= 1;
		if (sort_2(stack_a, 1, &(vars->ops_str)))
			vars->max_index -= 1;
		return (1);
	}
	else if (stack_b->top->content == ref[vars->max_index - 1])
	{
		p(stack_a, stack_b, FALSE, &(vars->ops_str));
		return (1);
	}
	return (0);
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b, int *ref, t_vars *vars)
{
	int	max_stack_index;

	max_stack_index = get_index(*stack_b, ref[vars->max_index]);
	if (max_stack_index == -1)
	{
		rr(stack_a, FALSE, &(vars->ops_str));
		vars->down_c -= 1;
		vars->max_index -= 1;
	}
	else if (!push_max(stack_a, stack_b, ref, vars))
	{
		if (vars->down_c == 0 && stack_b->top->content < stack_tail(*stack_a))
		{
			p(stack_a, stack_b, FALSE, &(vars->ops_str));
			r(stack_a, FALSE, &(vars->ops_str));
			vars->down_c += 1;
		}
		else
		{
			if (max_stack_index <= stack_b->size / 2)
				r(stack_b, FALSE, &(vars->ops_str));
			else
				rr(stack_b, FALSE, &(vars->ops_str));
		}
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	t_vars	vars;

	vars.down_c = 0;
	vars.max_index = stack_b->size - 1;
	vars.ops_str = NULL;
	while (stack_b->size > 0)
		push_to_a(stack_a, stack_b, ref_array, &vars);
	while ((vars.down_c)-- > 0)
		rr(stack_a, FALSE, &(vars.ops_str));
	print_merged_ops(vars.ops_str);
	free(vars.ops_str);
}
