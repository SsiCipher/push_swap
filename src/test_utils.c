/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:07:39 by yanab             #+#    #+#             */
/*   Updated: 2021/12/29 21:32:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack_top, char stack_id)
{
	int	i;

	i = 1;
	printf("Stack {%c}:\n", stack_id);
	if (stack_top == NULL)
		printf("\tStack is empty\n");
	while (stack_top != NULL)
	{
		printf("\tNode [%d]: %d\n", i++, stack_top->content);
		stack_top = stack_top -> next;
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
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
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
