/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:40:41 by yanab             #+#    #+#             */
/*   Updated: 2022/03/24 13:38:12 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// parses the new args from the current
char	**parse_args(int count, const char **args, int *new_count)
{
	int		i;
	char	*joined_args;
	char	*temp;
	char	**new_args;

	joined_args = NULL;
	i = -1;
	while (++i < count)
	{
		temp = joined_args;
		joined_args = ft_strjoin(joined_args, args[i]);
		free(temp);
		temp = joined_args;
		joined_args = ft_strjoin(joined_args, " ");
		free(temp);
	}
	i = -1;
	new_args = ft_split(joined_args, ' ');
	while (new_args[++i])
		*new_count += 1;
	return (new_args);
}

// check if an array of strings contains duplicates
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

// ft_atoi + checking if the nbr contains any non-integer or is out of INT range
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

// creates the initial stack
void	init_stack(t_stack **stack_top, int count, char **strs)
{
	int		n;
	t_stack	*new_node;

	if (!check_dup(count, strs))
		print_err("Error: the arguments given contain duplicates\n");
	while (count--)
	{
		n = atoi_check(strs[count]);
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			print_err("Error: failed to allocate memory\n");
		new_node->content = n;
		new_node->next = NULL;
		stack_push(stack_top, new_node);
	}
}

int cmp(int a, int b)
{
	return (a - b);
}

int get_index(int *arr, int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
			return (i);
	}
	return (-1);
}

void index_stack(t_stack *stack_top, int stack_size)
{
	int *sorted_arr;

	sorted_arr = malloc(sizeof(int) * stack_size);
	int i = 0;
	t_stack *curr = stack_top;
	while (curr)
	{
		sorted_arr[i] = curr->content;
		curr = curr->next;
		i++;
	}
	ft_qsort(sorted_arr, stack_size, cmp);
	curr = stack_top;
	while (curr)
	{
		curr->order_index = get_index(sorted_arr, stack_size, curr->content);
		curr = curr->next;
	}
}
