/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 07:25:30 by yanab             #+#    #+#             */
/*   Updated: 2022/03/21 14:08:22 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void s(t_stack **stack_top, char stack)
{
	write(1, "s", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	stack_swap(stack_top);
}

void p(t_stack **stack_top, t_stack *opp_stack_top, char stack)
{
	write(1, "p", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	stack_push(stack_top, opp_stack_top);
}

void r(t_stack **stack_top, char stack)
{
	write(1, "r", 1);
	write(1, &stack, 1);
	write(1, "\n", 1);
	stack_rotate(stack_top);
}

void rr(t_stack **stack_top, char stack)
{
	write(1, "rr", 2);
	write(1, &stack, 1);
	write(1, "\n", 1);
	stack_rrotate(stack_top);
}
