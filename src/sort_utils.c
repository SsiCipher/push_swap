/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 05:54:07 by yanab             #+#    #+#             */
/*   Updated: 2022/04/17 01:12:35 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_push_b(t_stack *stack_a, t_stack *stack_b, int *ref_array)
{
	int	max_value;
	int	max_value_index;
	int	next_max_value;

	while (stack_b->size > 0)
	{
		max_value = ref_array[stack_b->size - 1];
		max_value_index = get_index(*stack_b, max_value);
		next_max_value = ref_array[stack_b->size - 2];
		while (stack_b->top->content != max_value)
		{
			if (stack_b->top->content == next_max_value)
				p(stack_a, stack_b, TRUE, 'a');
			else
			{
				if (max_value_index <= stack_b->size / 2)
					r(stack_b, TRUE, 'b');
				else
					rr(stack_b, TRUE, 'b');
			}
		}
		p(stack_a, stack_b, TRUE, 'a');
		if (stack_a->size >= 2)
		{
			if (stack_a->top->content > stack_a->top->next->content)
				s(stack_a, TRUE, 'a');
		}
	}
}

void	set_chunk_size(int size, int *chunk_size)
{
	if (size <= 30)
		*chunk_size = size / 5;
	else if (size <= 100)
		*chunk_size = size / 8;
	else
		*chunk_size = size / 18;
}

void	expand_range(int size, int chunk_size, int *low, int *high)
{
	if (*low - chunk_size < 0)
		*low = 0;
	else
		*low -= chunk_size;
	if (*high + chunk_size > size)
		*high = size;
	else
		*high += chunk_size;
}

void	concat_op(char **ops_str, char *new_op)
{
	char	*tmp;

	tmp = *ops_str;
	*ops_str = ft_strjoin(*ops_str, new_op);
	free(tmp);
}

void	print_merged_ops(char *ops_str)
{
	int		i;
	char	**ops;

	i = 0;
	ops = ft_split(ops_str, '\n');
	while (ops[i])
	{
		if (
			(!ft_strcmp(ops[i], "rb") && !ft_strcmp(ops[i + 1], "ra"))
			|| (!ft_strcmp(ops[i], "ra") && !ft_strcmp(ops[i + 1], "rb"))
		)
		{
			write(1, "rr\n", 3);
			i += 2;
		}
		else
		{
			write(1, ops[i], ft_strlen(ops[i]));
			write(1, "\n", 1);
			i++;
		}
	}
}
