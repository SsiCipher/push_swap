/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 05:54:07 by yanab             #+#    #+#             */
/*   Updated: 2022/04/24 00:26:43 by yanab            ###   ########.fr       */
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

int	merge_ops(char **ops, int i)
{
	if (
		(!ft_strcmp(ops[i], "rb") && !ft_strcmp(ops[i + 1], "ra"))
		|| (!ft_strcmp(ops[i], "ra") && !ft_strcmp(ops[i + 1], "rb")))
	{
		write(1, "rr\n", 3);
		return (1);
	}
	else if (
		(!ft_strcmp(ops[i], "sb") && !ft_strcmp(ops[i + 1], "sa"))
		|| (!ft_strcmp(ops[i], "sa") && !ft_strcmp(ops[i + 1], "sb")))
	{
		write(1, "ss\n", 3);
		return (1);
	}
	else if (
		(!ft_strcmp(ops[i], "rrb") && !ft_strcmp(ops[i + 1], "rra"))
		|| (!ft_strcmp(ops[i], "rra") && !ft_strcmp(ops[i + 1], "rrb")))
	{
		write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}

void	print_merged_ops(char *ops_str)
{
	int		i;
	char	**ops;

	i = 0;
	ops = ft_split(ops_str, '\n');
	while (ops[i])
	{
		if (merge_ops(ops, i))
		{
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
