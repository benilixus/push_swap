/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:37:24 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/14 14:54:34 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	all_digits(char *args)
{
	int	i;

	i = 0;
	if (args[i] == '-' || args[i] == '+')
		i++;
	if (!args[i])
		return (1);
	while (args[i])
	{
		if (!is_digit(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(t_lst *a, int n)
{
	while (a)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_empty_arg(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (1);
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_ovflow(long n)
{
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

void	process_arg(t_lst **a, char *str)
{
	char	**split_args;
	t_lst	*new;
	int		j;
	long	n;

	split_args = ft_split(str);
	if (!split_args)
		error_exit(a, NULL, 0);
	j = 0;
	while (split_args[j])
	{
		if (all_digits(split_args[j]))
			error_exit(a, split_args, 1);
		n = ft_atol(split_args[j]);
		if (check_ovflow(n))
			error_exit(a, split_args, 1);
		if (check_dup(*a, (int)n))
			error_exit(a, split_args, 1);
		new = newlst((int)n, -1);
		if (!new)
			error_exit(a, split_args, 1);
		addback(a, new);
		j++;
	}
	free_split(split_args);
}
