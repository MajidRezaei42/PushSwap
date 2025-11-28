/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:33:33 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/20 23:33:34 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_node(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match;

	while (b)
	{
		current_a = a;
		best_match = LONG_MAX;
		while (current_a)
		{
			if (b->value < current_a->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			target_node = find_min(a);
		b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->push_cost = b->index;
		if (b->above_median == 0)
			b->push_cost = len_b - b->index;
		if (b->target_node->above_median == 1)
			b->push_cost = b->push_cost + b->target_node->index;
		else
			b->push_cost = b->push_cost + (len_a - b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	best_match;
	t_node	*best_match_node;
	t_node	*current;

	if (!stack)
		return ;
	best_match_node = NULL;
	current = stack;
	best_match = LONG_MAX;
	while (current)
	{
		if (current->push_cost < best_match)
		{
			best_match = current->push_cost;
			best_match_node = current;
		}
		current = current->next;
	}
	best_match_node->cheapest = 1;
}

void	min_to_top(t_node **stack)
{
	t_node	*min_node;

	min_node = (find_min(*stack));
	while ((*stack) != min_node)
	{
		if (min_node->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > (stack->next)->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
