/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:05:19 by yanab             #+#    #+#             */
/*   Updated: 2022/04/22 01:23:31 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libs/libft/libft.h"

typedef struct s_node
{
	int				index;
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	char	name;
}	t_stack;

// src/init_data.c
void	parse_args(int argc, char **argv, int *new_argc, char ***new_argv);
bool	contains_dups(int argc, char **argv);
int		atoi_check(char *number);
void	init_stack(t_stack *stack, int argc, char **argv);
int		*index_stack(t_stack stack);

// src/stack.c
t_node	*create_node(int content);
void	stack_push(t_stack *stack, t_node *new_node);
t_node	*stack_pop(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack, int direction);

// src/stack_utils.c
int		is_stack_sorted(t_stack stack);
int		stack_max(t_stack stack, int *max_value);
int		stack_min(t_stack stack, int *min_value, int *next_min);
int		get_index(t_stack stack, int value);
int		stack_tail(t_stack stack);

// src/operations.c
void	s(t_stack *stack, bool print_op, char **ops_str);
void	p(t_stack *to, t_stack *from, bool print_op, char **ops_str);
void	r(t_stack *stack, bool print_op, char **ops_str);
void	rr(t_stack *stack, bool print_op, char **ops_str);

// src/sort.c
int		sort_2(t_stack *stack, int direction);
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
void	sort_long(t_stack *stack_a, t_stack *stack_b, int *ref_array);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b, int *ref_array);

// src/sort_utils.c
void	set_chunk_size(int size, int *chunk_size);
void	concat_op(char **ops_str, char *new_op);
void	print_merged_ops(char *ops_str);
void	expand_range(int size, int chunk_size, int *low, int *high);
int		smart_rotate(t_stack *stack, int min, int max);

// src/sort_utils2.c
void	a_to_b(t_stack *stack_a, t_stack *stack_b, int range[2], char **ops);
void	b_to_a(t_stack *stack_a, t_stack *stack_b, int *ref_array);

// src/test_utils.c
void	print_ops_count(void);
void	print_stacks(t_stack stack_a, t_stack stack_b);
void	print_info(t_stack *stack_a, t_stack *stack_b);
void	interactive_tester(t_stack *stack_a, t_stack *stack_b);

// push_swap.c
void	print_error(char *error);

#endif
