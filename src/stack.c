/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 07:23:42 by yanab             #+#    #+#             */
/*   Updated: 2022/04/02 05:42:20 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push node to stack top
void	stack_push(t_stack **stack_top, t_stack *new_node)
{
	if (!new_node)
		return ;
	if (!*stack_top)
		new_node->index = 1;
	else
		new_node->index = (*stack_top)->index + 1;
	new_node->order_index = -1;
	if (new_node)
	{
		new_node->next = *stack_top;
		*stack_top = new_node;
	}
}

// Pop node from stack top
t_stack	*stack_pop(t_stack **stack_top)
{
	t_stack	*tmp;

	if (!(*stack_top))
		return (NULL);
	tmp = *stack_top;
	*stack_top = (*stack_top)->next;
	tmp->next = NULL;
	return (tmp);
}

// Swap the first 2 nodes in stack
void	stack_swap(t_stack **stack_top)
{
	t_stack	*top;
	int		tmp;

	top = *stack_top;
	if (*stack_top != NULL && (*stack_top)->next != NULL)
	{
		tmp = (*stack_top)->content;
		(*stack_top)->content = top->next->content;
		top->next->content = tmp;
	}
}

// Rotate stack up by 1
void	stack_rotate(t_stack **stack_top)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_top != NULL && (*stack_top)->next != NULL)
	{
		tmp = (*stack_top)->next;
		last = (*stack_top)->next;
		(*stack_top)->next = NULL;
		while (last->next)
		{
			last->index += 1;
			last = last->next;
		}
		last->index += 1;
		last->next = *stack_top;
		last->next->index = 1;
		*stack_top = tmp;
	}
}

// Rotate stack down by 1
void	stack_rrotate(t_stack **stack_top)
{
	t_stack	*last;
	t_stack	*curr;

	curr = *stack_top;
	last = *stack_top;
	if (*stack_top != NULL && (*stack_top)->next != NULL)
	{
		while (last->next)
		{
			last->index -= 1;
			last = last->next;
		}
		while (curr->next->next != NULL)
			curr = curr->next;
		last->next = *stack_top;
		last->index = (*stack_top)->index + 1;
		*stack_top = last;
		curr->next = NULL;
	}
}
