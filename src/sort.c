/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:04:33 by yanab             #+#    #+#             */
/*   Updated: 2021/12/29 21:27:14 by marvin           ###   ########.fr       */
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

void	bsort_tmp_arr(int length, int **arr)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < length)
	{
		j = i;
		while (++j < length)
		{
			if ((*arr)[i] > (*arr)[j])
			{
				tmp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = tmp;
			}
		}
	}
}

int	cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void	qsort_tmp_arr(int length, int **arr)
{
	qsort(*arr, length, sizeof(int), cmpfunc);
}
