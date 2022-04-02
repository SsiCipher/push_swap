/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:05:19 by yanab             #+#    #+#             */
/*   Updated: 2022/04/02 05:28:45 by yanab            ###   ########.fr       */
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
}	t_node;

typedef struct s_stack
{
	t_node	*stack_top;
	int		stack_size;
}	t_stack;

#endif
