/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 01:09:13 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/22 01:09:15 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int		size;
	t_node	*last_node;

	size = 0;
	last_node = stack;
	while (last_node)
	{
		last_node = last_node->next;
		size++;
	}
	return (size);
}

void	set_current_index(t_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

t_node	*find_last(t_node *stack)
{
	t_node	*last_node;

	if (!stack)
		return (NULL);
	last_node = stack;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}
