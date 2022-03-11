/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:14:04 by cipher            #+#    #+#             */
/*   Updated: 2022/03/11 08:16:20 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stack_max(t_stack *stack_top, int *index, int *next_max)
{
	int	i;
	int	max;

	i = 0;
	max = stack_top->content;
	*next_max = stack_top->content;
	while (stack_top != NULL)
	{
		if (stack_top->content > max)
		{
			*index = i;
			*next_max = max;
			max = stack_top->content;
		}
		else
		{
			if (stack_top->content > *next_max)
				*next_max = stack_top->content;
		}
		i++;
		stack_top = stack_top->next;
	}
	return (max);
}

int	get_stack_min(t_stack *stack_top, int *index, int *next_min)
{
	int	i;
	int	min;

	i = 0;
	min = stack_top->content;
	*next_min = stack_top->content;
	while (stack_top != NULL)
	{
		if (stack_top->content < min)
		{
			*index = i;
			*next_min = min;
			min = stack_top->content;
		}
		else
		{
			if (stack_top->content < *next_min)
				*next_min = stack_top->content;
		}
		i++;
		stack_top = stack_top->next;
	}
	return (min);
}
