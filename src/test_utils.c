/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:44:47 by yanab             #+#    #+#             */
/*   Updated: 2022/04/12 02:58:09 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops_count(void)
{
	static int	count = 0;

	printf("Operations Count: [%d]\n", count);
	count++;
}

void	print_stacks(t_stack stack_a, t_stack stack_b)
{
	int		start;
	t_node	*a_top;
	t_node	*b_top;

	a_top = stack_a.stack_top;
	b_top = stack_b.stack_top;
	start = a_top != NULL;
	printf("STACK A [%d]:", stack_a.stack_size);
	while (stack_a.stack_top != a_top || start)
	{
		printf("  [%d]", stack_a.stack_top->content);
		stack_a.stack_top = stack_a.stack_top->next
			? stack_a.stack_top->next
			: stack_a.stack_top;
		start = 0;
	}
	printf("\n");
	printf("STACK B [%d]:", stack_b.stack_size);
	start = b_top != NULL;
	while (stack_b.stack_top != b_top || start)
	{
		printf("  [%d]", stack_b.stack_top->content);
		stack_b.stack_top = stack_b.stack_top->next
			? stack_b.stack_top->next
			: stack_b.stack_top;
		start = 0;
	}
	printf("\n");
}

void	print_info(t_stack *stack_a, t_stack *stack_b)
{
	print_ops_count();
	print_stacks(*stack_a, *stack_b);
}

void	interactive_tester(t_stack *stack_a, t_stack *stack_b)
{
	char	op[5];

	while (1)
	{
		printf("\nRun Operation #> ");
		scanf("%s", op);
		if (!strncmp(op, "sa", 2))
		{
			printf("\n");
			s(stack_a, TRUE, 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "sb", 2))
		{
			printf("\n");
			s(stack_b, TRUE, 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "pa", 2))
		{
			printf("\n");
			p(stack_a, stack_b, TRUE, 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "pb", 2))
		{
			printf("\n");
			p(stack_b, stack_a, TRUE, 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "ra", 2))
		{
			printf("\n");
			r(stack_a, TRUE, 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "rb", 2))
		{
			printf("\n");
			r(stack_b, TRUE, 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "rra", 3))
		{
			printf("\n");
			rr(stack_a, TRUE, 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "rrb", 3))
		{
			printf("\n");
			rr(stack_b, TRUE, 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "exit", 4))
			break ;
		else
			printf("Wrong operation: [%s]\n", op);
	}
}
