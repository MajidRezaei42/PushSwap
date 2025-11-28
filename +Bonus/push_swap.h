/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:41:15 by arezaei           #+#    #+#             */
/*   Updated: 2025/09/24 11:41:16 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* INCLUDING LIBRARIES-------------- */
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
/* library required for perror */
# include <errno.h>
# include <stdio.h>
/* library required for open, close... */
# include <fcntl.h>
/* library required for wait() */
# include <sys/wait.h>
# include <unistd.h>
/* library required for LONG_MAX */
# include <limits.h>

/* DEFINING STRUCT------------------ */
typedef struct s_node
{
	int				value;
	int				index;
	int				above_median;
	int				push_cost;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* PROTOTYPES------------------------*/
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **a, t_node **b);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **a, t_node **b);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **a, t_node **b);
int		args_not_valid(int argc, char **argv);
void	sort_three(t_node **a);
void	get_target_node(t_node *a, t_node *b);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *stack);
void	min_to_top(t_node **stack);
int		is_sorted(t_node *stack);
void	move_b_to_a(t_node **a, t_node **b);
t_node	*init_node(int value);
void	stack_add_back(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);
t_node	*find_min(t_node *stack);
int		stack_size(t_node *stack);
void	set_current_index(t_node *stack);
t_node	*find_last(t_node *stack);
long	ft_atol(const char *str);
#endif
