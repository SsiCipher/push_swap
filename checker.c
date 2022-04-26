/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:07:56 by yanab             #+#    #+#             */
/*   Updated: 2022/04/26 01:58:07 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	push_swap_ops(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(op, "pa\n", 3))
		p(stack_a, stack_b, FALSE, NULL);
	else if (!ft_strncmp(op, "pb\n", 3))
		p(stack_b, stack_a, FALSE, NULL);
	else if (!ft_strncmp(op, "sa\n", 3))
		s(stack_a, FALSE, NULL);
	else if (!ft_strncmp(op, "sb\n", 3))
		s(stack_b, FALSE, NULL);
	else if (!ft_strncmp(op, "ss\n", 3))
	{
		s(stack_a, FALSE, NULL);
		s(stack_b, FALSE, NULL);
	}
	else
		return (0);
	return (1);
}

int	rotate_rrotate_ops(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(op, "ra\n", 3))
		r(stack_a, FALSE, NULL);
	else if (!ft_strncmp(op, "rb\n", 3))
		r(stack_b, FALSE, NULL);
	else if (!ft_strncmp(op, "rr\n", 3))
	{
		r(stack_a, FALSE, NULL);
		r(stack_b, FALSE, NULL);
	}
	else if (!ft_strncmp(op, "rra\n", 4))
		rr(stack_a, FALSE, NULL);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rr(stack_b, FALSE, NULL);
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		rr(stack_a, FALSE, NULL);
		rr(stack_b, FALSE, NULL);
	}
	else
		return (0);
	return (1);
}

void	apply_ops(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (
			!push_swap_ops(op, stack_a, stack_b)
			&& !rotate_rrotate_ops(op, stack_a, stack_b)
		)
			print_error("Error:\ninvalid operation");
		op = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*ref_array;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	stack_b.size = 0;
	stack_b.top = NULL;
	stack_b.name = 'b';
	stack_a.name = 'a';
	init_stack(&stack_a, argc - 1, argv + 1);
	if (stack_a.size <= 1)
		exit(EXIT_SUCCESS);
	ref_array = index_stack(stack_a);
	apply_ops(&stack_a, &stack_b);
	if (is_stack_sorted(stack_a) && stack_b.size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(ref_array);
	return (0);
}
