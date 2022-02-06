/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:40:41 by yanab             #+#    #+#             */
/*   Updated: 2022/02/06 23:52:50 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dup(int count, char **strs)
{
	int	i;

	while (--count)
	{
		i = -1;
		while (++i < count)
		{
			if (!strcmp(strs[count], strs[i]))
				return (0);
		}
	}
	return (1);
}

int	atoi_check(char *nbr)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	if (nbr[i] == '-' || nbr[i] == '+')
		if (nbr[i++] == '-')
			sign *= -1;
	num = 0;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			print_err("Error: the arguments given contain a non integer\n");
		num = num * 10 + (nbr[i++] - '0');
	}
	if (sign * num <= INT_MIN || sign * num >= INT_MAX)
		print_err("Error: the arguments given are out of integer range\n");
	return (sign * num);
}

char	**alloc_args(int count, const char **args, int *new_count)
{
	int		i;
	int		parts;
	char	**strs;

	i = -1;
	parts = 0;
	while (++i < count)
	{
		if (ft_strchr(args[i], ' '))
			parts += ft_countchr((char *)args[i], ' ') + 1;
		else
			parts++;
	}
	strs = (char **)malloc(sizeof(char *) * (parts + 1));
	*new_count = parts;
	return (strs);
}

char	**parse_args(int count, const char **args, int *new_count)
{
	int		i;
	int		j;
	char	**tmp;
	char	**s;
	char	**strs;

	i = -1;
	j = 0;
	strs = alloc_args(count, args, new_count);
	while (++i < count)
	{
		if (!ft_strchr(args[i], ' '))
			strs[j++] = ft_strdup(args[i]);
		else
		{
			s = ft_split(args[i], ' ');
			tmp = s;
			while (*s)
				strs[j++] = *(s++);
			free(tmp);
		}
	}
	strs[j] = NULL;
	return (strs);
}

int	*init_stack(t_stack **stack_top, int count, char **strs)
{
	int		n;
	t_stack	*new_node;
	int		*tmp_arr;

	if (!check_dup(count, strs))
		print_err("Error: the arguments given contain duplicates\n");
	tmp_arr = (int *)malloc(sizeof(int) * count);
	if (!tmp_arr)
		print_err("Error: failed to allocate memory\n");
	while (count--)
	{
		n = atoi_check(strs[count]);
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			print_err("Error: failed to allocate memory\n");
		new_node->content = n;
		new_node->next = NULL;
		tmp_arr[count] = n;
		stack_push(stack_top, new_node);
	}
	return (tmp_arr);
}
