/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:38:18 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/21 16:38:20 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_cheapest(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current)
	{
		if (current->cheapest == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	prep_to_push(t_node **stack, char stack_name, t_node *moving_node)
{
	while (moving_node != *stack)
	{
		if (moving_node->above_median)
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
		}
		set_current_index(*stack);
	}
}

void	move_b_to_a(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*b);
	while (cheapest->above_median
		&& (cheapest->target_node)->above_median
		&& cheapest != *b && cheapest->target_node != *a)
	{
		rr(a, b);
		set_current_index(*a);
		set_current_index(*b);
	}
	while (cheapest->above_median == 0
		&& (cheapest->target_node)->above_median == 0
		&& cheapest != *b && cheapest->target_node != *a)
	{
		rrr(a, b);
		set_current_index(*a);
		set_current_index(*b);
	}
	prep_to_push(b, 'b', cheapest);
	prep_to_push(a, 'a', cheapest->target_node);
	pa(a, b);
}
