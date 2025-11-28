/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezaei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:05:27 by arezaei           #+#    #+#             */
/*   Updated: 2025/11/17 11:05:29 by arezaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	err_syntax(char *str_n)
{
	int	i;

	i = 0;
	if (str_n[0] == '+' || str_n[0] == '-')
		i++;
	if (str_n[i] == '\0')
		return (1);
	while (str_n[i] != '\0')
	{
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	err_int_limit(char *str_n)
{
	long	num;

	num = ft_atol(str_n);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

static int	err_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	err_message(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	args_not_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (err_syntax(argv[i]) || err_int_limit(argv[i]))
			return (err_message());
		i++;
	}
	if (err_duplicates(argc, argv))
		return (err_message());
	return (0);
}

/*
int	err_duplicates_node(t_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}
*/