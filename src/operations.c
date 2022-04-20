/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:37:33 by yanab             #+#    #+#             */
/*   Updated: 2022/04/19 22:07:08 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack, bool print_op, char stack_name)
{
	stack_swap(stack);
	if (print_op)
	{
		write(1, "s", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	p(t_stack *to, t_stack *from, bool print_op, char stack_name)
{
	stack_push(to, stack_pop(from));
	if (print_op)
	{
		write(1, "p", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	r(t_stack *stack, bool print_op, char stack_name)
{
	stack_rotate(stack, 1);
	if (print_op)
	{
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	rr(t_stack *stack, bool print_op, char stack_name)
{
	stack_rotate(stack, -1);
	if (print_op)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}
