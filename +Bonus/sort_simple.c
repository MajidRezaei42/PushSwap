/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:25:26 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/18 20:25:27 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	int		biggest;

	first = *a;
	second = first->next;
	third = (first->next)->next;
	if ((third->value > first-> value) && (third->value > second-> value))
		biggest = third->value;
	else if ((second->value > first-> value) && (second-> value > third->value))
		biggest = second-> value;
	else
		biggest = first-> value;
	if (biggest == first->value)
		ra(a);
	else if (biggest == second->value)
		rra(a);
	if ((*a)->value > ((*a)->next)->value)
		sa(a);
}
