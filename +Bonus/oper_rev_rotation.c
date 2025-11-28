/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rev_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:18:00 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/21 23:18:01 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*prev_last;
	t_node	*last;

	first = *stack;
	if (!first || !(first->next))
		return ;
	last = find_last(*stack);
	prev_last = last->prev;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	prev_last->next = NULL;
	*stack = last;
}

void	rra(t_node **stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
