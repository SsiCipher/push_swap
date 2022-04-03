/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:40:24 by yanab             #+#    #+#             */
/*   Updated: 2022/04/03 05:48:07 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_max(t_stack stack, int *prev_max)
{
	int	i;
	int	max;

	i = 0;
	max = stack.stack_top->content;
	*prev_max = stack_top->content;
	while (i < stack.stack_size)
	{
		
	}
}