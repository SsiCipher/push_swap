/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:40:24 by yanab             #+#    #+#             */
/*   Updated: 2022/04/13 01:59:49 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack stack)
{
	int		size;

	size = stack.size;
	while (--size)
	{
		if (stack.top->content > stack.top->next->content)
			return (0);
		stack.top = stack.top->next;
	}
	return (1);
}

int	stack_max(t_stack stack, int *max_value)
{
	int	i;
	int	max_index;

	i = 0;
	max_index = -1;
	*max_value = INT_MIN;
	while (i < stack.size)
	{
		if (stack.top->content > *max_value)
		{
			*max_value = stack.top->content;
			max_index = i;
		}
		stack.top = stack.top->next;
		i++;
	}
	return (max_index);
}

int	stack_min(t_stack stack, int *min_value, int *next_min)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = -1;
	*min_value = INT_MAX;
	*next_min = INT_MAX;
	while (i < stack.size)
	{
		if (stack.top->content <= *min_value)
		{
			*next_min = *min_value;
			*min_value = stack.top->content;
			min_index = i;
		}
		else if (stack.top->content < *next_min)
			*next_min = stack.top->content;
		stack.top = stack.top->next;
		i++;
	}
	return (min_index);
}
