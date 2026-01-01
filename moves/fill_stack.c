/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:25:51 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 18:42:02 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_lst **a, char **args, int use_split)
{
	free_stack(a);
	if (use_split)
		free_split(args);
	ft_putsrt("Error\n", 2);
	exit(1);
}

void	fill_stack(t_lst **a, char **v, int use_split)
{
	long	n;
	int		i;

	i = 0;
	while (v[i])
	{
		if (!all_digits(v[i]))
			error_exit(a, v, use_split);
		n = ft_atol(v[i]);
		if (check_ovflow(n))
			error_exit(a, v, use_split);
		if (check_dup(*a, (int)n))
			error_exit(a, v, use_split);
		addback(a, newlst((int)n, -1));
		i++;
	}
}
