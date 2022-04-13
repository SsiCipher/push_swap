/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:37:35 by yanab             #+#    #+#             */
/*   Updated: 2022/04/13 01:59:49 by yanab            ###   ########.fr       */
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

	if (!new_node)
		return ;
	if (stack->size == 0)
		stack->top = new_node;
	else
	{
		size = stack->size;
		last_node = stack->top;
		while (--size)
			last_node = last_node->next;
		new_node->next = stack->top;
		new_node->prev = last_node;
		last_node->next = new_node;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size += 1;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top == NULL)
		return (NULL);
	tmp = stack->top;
	if (stack->size >= 2)
	{
		stack->top->prev->next = stack->top->next;
		stack->top->next->prev = stack->top->prev;
	}
	if (stack->size == 1)
		stack->top = NULL;
	else
		stack->top = stack->top->next;
	stack->size -= 1;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = tmp;
}

void	stack_rotate(t_stack *stack, int direction)
{
	if (stack->size <= 1)
		return ;
	if (direction == 1)
		stack->top = stack->top->next;
	else if (direction == -1)
		stack->top = stack->top->prev;
}
