/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:32:08 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/14 19:32:13 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		set_current_index(*b);
		set_current_index(*a);
		get_target_node(*a, *b);
		set_price(*a, *b);
		set_cheapest(*b);
		move_b_to_a(a, b);
	}
	if (!is_sorted(*a))
	{
		set_current_index(*a);
		min_to_top(a);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*new_node;
	int		i;

	if (argc <= 1)
		return (0);
	if (args_not_valid(argc, argv))
		return (0);
	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
	{
		new_node = init_node(ft_atol(argv[i]));
		stack_add_back(&a, new_node);
		i++;
	}
	if (!is_sorted(a))
		sort_stacks(&a, &b);
	free_stack(&a);
	return (0);
}
