/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:25:28 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/21 23:25:29 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	if (second->next)
		((second->next)->prev) = first;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
