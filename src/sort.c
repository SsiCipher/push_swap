/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:04:33 by yanab             #+#    #+#             */
/*   Updated: 2022/02/04 02:12:32 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(int length, int *arr)
{
	int	i;

	i = 0;
	while (++i < length)
	{
		if (arr[i] < arr[i - 1])
			return (0);
	}
	return (1);
}

void	sort_2(t_stack **stack_a)
{
	int arr[3];
	arr[0] = (*stack_a)->content;
	arr[1] = (*stack_a)->next->content;
	arr[2] = (*stack_a)->next->next->content;
	while (!is_sorted(3, arr))
	{
		if (arr[0] > arr[1] && arr[0] > arr[2])
			r(stack_a, 'a');
		else if (arr[1] > arr[0] && arr[1] > arr[2])
			rr(stack_a, 'a');
		else if (arr[0] > arr[1])
			s(stack_a, 'a');
		arr[0] = (*stack_a)->content;
		arr[1] = (*stack_a)->next->content;
		arr[2] = (*stack_a)->next->next->content;
	}
}

// void	sort_5(t_stack **stack_a, t_stack **stack_b)
// {
	
// }

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_size;

	(void)stack_b;
	stack_a_size = (*stack_a)->index;

	if (stack_a_size == 2 && (*stack_a)->content > (*stack_a)->next->content)
		s(stack_a, 'a');
	else if (stack_a_size == 3)
		sort_2(stack_a);
	// else if (stack_a_size == 5)
		// sort_5(stack_a, stack_b);
}
