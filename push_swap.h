/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:05:19 by yanab             #+#    #+#             */
/*   Updated: 2022/04/05 03:37:12 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>	// DELETE
# include <string.h> // DELETE
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
	t_node	*stack_top;
	int		stack_size;
}	t_stack;

// stack.c
t_node	*create_node(int content);
void	stack_push(t_stack *stack, t_node *new_node);
t_node	*stack_pop(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack, int direction);

// stack_utils.c
int		stack_max(t_stack stack, int *max_value);
int		stack_min(t_stack stack, int *min_value);

// operations.c
void	s(t_stack *stack, bool print_op, char stack_name);
void	p(t_stack *stack, t_stack *opp_stack, bool print_op, char stack_name);
void	r(t_stack *stack, bool print_op, char stack_name);
void	rr(t_stack *stack, bool print_op, char stack_name);

// init_data.c
void	parse_args(int argc, char **argv, int *new_argc, char ***new_argv);
bool	contains_dups(int argc, char **argv);
int		atoi_check(char *number);
void	init_stack(t_stack *stack, int argc, char **argv);

// test_utils.c
void	print_ops_count(void);
void	print_stacks(t_stack stack_a, t_stack stack_b);
void	interactive_tester(t_stack *stack_a, t_stack *stack_b);

// push_swap.c
void	print_error(char *error);

#endif
