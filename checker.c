/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:45:21 by yanab             #+#    #+#             */
/*   Updated: 2022/03/27 18:35:15 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_err(char *error)
{
	while (*error)
		write(2, error++, 1);
	exit(1);
}

int	is_stack_sorted(t_stack *stack_top)
{
	t_stack	*curr;
	t_stack	*next;

	curr = stack_top;
	next = stack_top->next;
	while (next != NULL)
	{
		if (curr->content > next->content)
			return (0);
		curr = next;
		next = next->next;
	}
	return (1);
}

int	push_swap_ops(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(op, "pa\n"))
		p(stack_a, stack_pop(stack_b), 'a');
	else if (!ft_strcmp(op, "pb\n"))
		p(stack_b, stack_pop(stack_a), 'b');
	else if (!ft_strcmp(op, "sa\n"))
		s(stack_a, 'a');
	else if (!ft_strcmp(op, "sb\n"))
		s(stack_b, 'b');
	else if (!ft_strcmp(op, "ss\n"))
	{
		s(stack_a, 'a');
		s(stack_b, 'b');
	}
	else
		return (0);
	return (1);
}

int	rotate_rrotate_ops(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(op, "ra\n"))
		r(stack_a, 'a');
	else if (!ft_strcmp(op, "rb\n"))
		r(stack_b, 'b');
	else if (!ft_strcmp(op, "rr\n"))
	{
		r(stack_a, 'a');
		r(stack_b, 'b');
	}
	else if (!ft_strcmp(op, "rra\n"))
		rr(stack_a, 'a');
	else if (!ft_strcmp(op, "rrb\n"))
		rr(stack_b, 'b');
	else if (!ft_strcmp(op, "rrr\n"))
	{
		rr(stack_a, 'a');
		rr(stack_b, 'b');
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		args_count;
	char	*op;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		exit(0);
	args = parse_args(argc - 1, (const char **)argv + 1, &args_count);
	init_stack(&stack_a, args_count, args);
	op = get_next_line(0);
	while (op)
	{
		if (push_swap_ops(op, &stack_a, &stack_b)
			&& rotate_rrotate_ops(op, &stack_a, &stack_b))
			print_err("Invalid Operation\n");
		op = get_next_line(0);
	}
	if (is_stack_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
