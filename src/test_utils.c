/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:07:39 by yanab             #+#    #+#             */
/*   Updated: 2022/03/27 18:33:41 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	char	*a, *b;
	char	*a_i, *b_i;

	ft_putendl_fd("", 1);
	ft_putendl_fd("|\ti. a\t\ti. b\t|", 1);
	ft_putendl_fd("|\t----\t\t----\t|", 1);
	while (stack_a != NULL || stack_b != NULL)
	{
		a = stack_a ? ft_itoa(stack_a->content) : " ";
		b = stack_b ? ft_itoa(stack_b->content) : " ";
		a_i = stack_a ? ft_itoa(stack_a->index) : " ";
		b_i = stack_b ? ft_itoa(stack_b->index) : " ";
		printf("|\t%s. %s\t\t%s. %s\t|\n", a_i, a, b_i, b);
		stack_a = stack_a ? stack_a->next : stack_a;
		stack_b = stack_b ? stack_b->next : stack_b;
	}
	ft_putendl_fd("---------------------------------\n", 1);
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
			p(&stack_a, stack_pop(&stack_b), 'a');
			print_info(stack_a, stack_b);
		}
		else if (!strncmp(op, "pb", 2))
		{
			printf("\n");
			p(&stack_b, stack_pop(&stack_a), 'b');
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
