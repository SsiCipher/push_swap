/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:05:19 by yanab             #+#    #+#             */
/*   Updated: 2022/02/04 01:32:25 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "libs/libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
}	t_stack;

// stack.c
void	push_stack(t_stack **stack_top, t_stack *new_node);
t_stack	*pop_stack(t_stack **stack_top);
void	swap_stack(t_stack **stack_top);
void	rotate_stack(t_stack **stack_top);
void	rrotate_stack(t_stack **stack_top);

// operations.c
void	s(t_stack **stack_top, char stack);
void	p(t_stack **stack_top, t_stack *opp_stack_top, char stack);
void	r(t_stack **stack_top, char stack);
void	rr(t_stack **stack_top, char stack);

// check.c
void	print_err(char *str);
int		check_dup(int count, char **strs);
int		atoi_check(char *nbr);
int		*init_stack(t_stack **stack_top, int count, char **strs);

// sort.c
int		is_sorted(int length, int *arr);

// test_utils.c
void	print_stack(t_stack *stack_top, char stack_id);
void	print_ops_count(void);
void	start_interactive_tester(t_stack *stack_a, t_stack *stack_b);

#endif
