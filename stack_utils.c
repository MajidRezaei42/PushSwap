/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:09:34 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/17 11:09:35 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->above_median = 0;
	node->push_cost = INT_MAX;
	node->cheapest = 0;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!(*stack))
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if ((stack == NULL) || (*stack == NULL))
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

t_node	*find_min(t_node *stack)
{
	long	min_val;
	t_node	*min_node;
	t_node	*current;

	min_node = NULL;
	current = stack;
	min_val = LONG_MAX;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}
