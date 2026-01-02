/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:37:24 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/02 09:57:07 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (0);
		i++;
	}
	return (1);
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

int	check_ovflow(long n)
{
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}
