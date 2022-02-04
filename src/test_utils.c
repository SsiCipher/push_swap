/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:07:39 by yanab             #+#    #+#             */
/*   Updated: 2022/02/04 02:52:35 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	char	a, b;

	printf("\ta\tb\n");
	printf("\t-\t-\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		a = stack_a ? (stack_a->content + '0') : ' ';
		b = stack_b ? (stack_b->content + '0') : ' ';
		printf("\t%c\t%c\n", a, b);
		stack_a = stack_a ? stack_a->next : stack_a;
		stack_b = stack_b ? stack_b->next : stack_b;
	}
}

void	print_ops_count(void)
{
	static int	count = 0;

	printf("Operations Count: [%d]\n", count);
	count++;
}

void	print_info(t_stack *stack_a, t_stack *stack_b)
{
	print_ops_count();
	print_stacks(stack_a, stack_b);
}

void	start_interactive_tester(t_stack *stack_a, t_stack *stack_b)
{
	char	op[5];

	while (1)
	{
		printf("\nRun Operation #> ");
		scanf("%s", op);
		if (!strncmp(op, "sa", 2))
		{
			printf("\n");
			s(&stack_a, 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "sb", 2))
		{
			printf("\n");
			s(&stack_b, 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "pa", 2))
		{
			printf("\n");
			p(&stack_a, pop_stack(&stack_b), 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "pb", 2))
		{
			printf("\n");
			p(&stack_b, pop_stack(&stack_a), 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "ra", 2))
		{
			printf("\n");
			r(&stack_a, 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "rb", 2))
		{
			printf("\n");
			r(&stack_b, 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "rra", 3))
		{
			printf("\n");
			rr(&stack_a, 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "rrb", 3))
		{
			printf("\n");
			rr(&stack_b, 'b');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "exit", 4))
			break ;
		else
			printf("Wrong operation: [%s]\n", op);
	}
}
