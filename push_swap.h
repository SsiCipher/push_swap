/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:05:19 by yanab             #+#    #+#             */
/*   Updated: 2022/02/28 06:16:36 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // DELETE
# include <string.h> // DELETE
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libs/libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
}	t_stack;

// stack.c
void	stack_push(t_stack **stack_top, t_stack *new_node);
t_stack	*stack_pop(t_stack **stack_top);
void	stack_swap(t_stack **stack_top);
void	stack_rotate(t_stack **stack_top);
void	stack_rrotate(t_stack **stack_top);

// stack_ops.c
void	s(t_stack **stack_top, char stack);
void	p(t_stack **stack_top, t_stack *opp_stack_top, char stack);
void	r(t_stack **stack_top, char stack);
void	rr(t_stack **stack_top, char stack);

// args_check.c
int		check_dup(int count, char **strs);
int		atoi_check(char *nbr);
char	**alloc_args(int count, const char **args, int *new_count);
char	**parse_args(int count, const char **args, int *new_count);
void	init_stack(t_stack **stack_top, int count, char **strs);

// sort.c
void	sort_3(t_stack **stack_a);
void	sort_5_max(t_stack **stack_a, t_stack **stack_b);
void	sort_5_min(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

// stack_utils.c
int		get_stack_max(t_stack *stack_top, int *index, int *next_max);
int		get_stack_min(t_stack *stack_top, int *index, int *next_min);

// test_utils.c
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_ops_count(void);
void	print_info(t_stack *stack_a, t_stack *stack_b);
void	start_interactive_tester(t_stack *stack_a, t_stack *stack_b);

// push_swap.c
void	print_err(char *error);
int		is_sorted(int length, int *arr);
int		is_stack_sorted(t_stack *stack_top);

#endif
