/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 07:23:42 by yanab             #+#    #+#             */
/*   Updated: 2021/12/29 20:18:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push node to stack top
void	push_stack(t_stack **stack_top, t_stack *new_node)
{
	if (new_node)
	{
		new_node->next = *stack_top;
		*stack_top = new_node;
	}
}

// Pop node from stack top
t_stack	*pop_stack(t_stack **stack_top)
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
void	swap_stack(t_stack **stack_top)
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
void	rotate_stack(t_stack **stack_top)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_top != NULL && (*stack_top)->next != NULL)
	{
		tmp = (*stack_top)->next;
		last = (*stack_top)->next;
		(*stack_top)->next = NULL;
		while (last->next)
			last = last->next;
		last->next = *stack_top;
		*stack_top = tmp;
	}
}

// Rotate stack down by 1
void	rrotate_stack(t_stack **stack_top)
{
	t_stack	*last;
	t_stack	*curr;

	curr = *stack_top;
	last = *stack_top;
	if (*stack_top != NULL && (*stack_top)->next != NULL)
	{
		while (last->next)
			last = last->next;
		while (curr->next->next != NULL)
			curr = curr->next;
		last->next = *stack_top;
		*stack_top = last;
		curr->next = NULL;
	}
}
