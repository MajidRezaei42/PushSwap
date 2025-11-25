/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:13:37 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/21 19:13:38 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*node_to_move;
	t_node	*src_second;
	t_node	*dest_first;

	if (!(*src))
		return ;
	node_to_move = *src;
	src_second = (*src)->next;
	dest_first = *dest;
	if (src_second)
		src_second->prev = NULL;
	if (dest_first)
		dest_first->prev = node_to_move;
	node_to_move->prev = NULL;
	node_to_move->next = dest_first;
	*dest = node_to_move;
	*src = src_second;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
