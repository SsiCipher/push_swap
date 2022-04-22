/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:37:33 by yanab             #+#    #+#             */
/*   Updated: 2022/04/21 23:51:41 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack, bool print_op, char **ops_str)
{
	stack_swap(stack);
	if (print_op)
	{
		write(1, "s", 1);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
	else if (ops_str)
	{
		if (stack->name == 'a')
			concat_op(ops_str, "sa\n");
		else if (stack->name == 'b')
			concat_op(ops_str, "sb\n");
	}
}

void	p(t_stack *to, t_stack *from, bool print_op, char **ops_str)
{
	stack_push(to, stack_pop(from));
	if (print_op)
	{
		write(1, "p", 1);
		write(1, &(to->name), 1);
		write(1, "\n", 1);
	}
	else if (ops_str)
	{
		if (to->name == 'a')
			concat_op(ops_str, "pa\n");
		else if (to->name == 'b')
			concat_op(ops_str, "pb\n");
	}
}

void	r(t_stack *stack, bool print_op, char **ops_str)
{
	stack_rotate(stack, 1);
	if (print_op)
	{
		write(1, "r", 1);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
	else if (ops_str)
	{
		if (stack->name == 'a')
			concat_op(ops_str, "ra\n");
		else if (stack->name == 'b')
			concat_op(ops_str, "rb\n");
	}
}

void	rr(t_stack *stack, bool print_op, char **ops_str)
{
	stack_rotate(stack, -1);
	if (print_op)
	{
		write(1, "rr", 2);
		write(1, &(stack->name), 1);
		write(1, "\n", 1);
	}
	else if (ops_str)
	{
		if (stack->name == 'a')
			concat_op(ops_str, "rra\n");
		else if (stack->name == 'b')
			concat_op(ops_str, "rrb\n");
	}
}
