/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:27:37 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/02 11:28:44 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_lst	*a;
	t_lst	*b;
	char	**args;
	int		use_split;

	a = NULL;
	b = NULL;
	use_split = 0;
	if (c < 2)
		return (0);
	if (c == 2)
	{
		args = ft_split(v[1]);
		use_split = 1;
	}
	else
		args = v + 1;
	fill_stack(&a, args, use_split);
	if (use_split)
		free_split(args);
	if (!a || is_sorted(a))
		return (free_stack(&a), 0);
	if (!is_sorted(a))
		check(&a, &b);
	return (0);
}
