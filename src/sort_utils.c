/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 05:54:07 by yanab             #+#    #+#             */
/*   Updated: 2022/04/22 00:02:22 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_chunk_size(int size, int *chunk_size)
{
	if (size <= 30)
		*chunk_size = size / 5;
	else if (size <= 100)
		*chunk_size = size / 8;
	else
		*chunk_size = size / 18;
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
			|| (!ft_strcmp(ops[i], "ra") && !ft_strcmp(ops[i + 1], "rb")))
		{
			write(1, "rr\n", 3);
			free(ops[i]);
			free(ops[i + 1]);
			i += 2;
		}
		else
		{
			write(1, ops[i], ft_strlen(ops[i]));
			write(1, "\n", 1);
			free(ops[i]);
			i++;
		}
	}
	free(ops);
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

int	smart_rotate(t_stack *stack, int min, int max)
{
	int		start;
	int		end;
	t_node	*curr;

	start = 0;
	curr = stack->top;
	while (start < stack->size / 2)
	{
		if (curr->index >= min && curr->index < max)
			break ;
		curr = curr->next;
		start++;
	}
	end = 0;
	curr = stack->top->prev;
	while (end < stack->size / 2)
	{
		if (curr->index >= min && curr->index < max)
			break ;
		curr = curr->prev;
		end++;
	}
	return (start - end);
}
