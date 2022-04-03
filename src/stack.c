/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:37:35 by yanab             #+#    #+#             */
/*   Updated: 2022/04/03 05:39:37 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

void	stack_push(t_stack *stack, t_node *new_node)
{
	t_node	*last_node;
	int		size;

	if (stack->stack_top == NULL)
		stack->stack_top = new_node;
	else
	{
		last_node = stack->stack_top;
		size = stack->stack_size;
		while (--size)
			last_node = last_node->next;
		new_node->next = stack->stack_top;
		new_node->prev = last_node;
		last_node->next = new_node;
		stack->stack_top->prev = new_node;
		stack->stack_top = new_node;
	}
	stack->stack_size += 1;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*tmp;

	if (stack->stack_size == 0)
		return (NULL);
	tmp = stack->stack_top;
	if (stack->stack_size >= 2)
	{
		stack->stack_top->prev->next = stack->stack_top->next;
		stack->stack_top->next->prev = stack->stack_top->prev;
	}
	stack->stack_top = stack->stack_top->next;
	stack->stack_size -= 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->stack_size <= 1)
		return ;
	tmp = stack->stack_top->content;
	stack->stack_top->content = stack->stack_top->next->content;
	stack->stack_top->next->content = tmp;
}

void	stack_rotate(t_stack *stack, int direction)
{
	if (stack->stack_size <= 1)
		return ;
	if (direction == 1)
		stack->stack_top = stack->stack_top->next;
	else if (direction == -1)
		stack->stack_top = stack->stack_top->prev;
}
