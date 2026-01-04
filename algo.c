/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:02:40 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 19:23:53 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos(t_lst *lst, int target)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->index == target)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

void	butterfly(t_lst **a, t_lst **b)
{
	int	count;
	int	n;

	count = 0;
	if (lstsize(*a) <= 100)
		n = 15;
	else
		n = 30;
	while (*a)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else if ((*a)->index <= count + n)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
}

void	butterfly_return(t_lst **a, t_lst **b)
{
	int	size;
	int	max_idx;
	int	pos;

	while (*b)
	{
		size = lstsize(*b);
		max_idx = size - 1;
		pos = get_pos(*b, max_idx);
		if (pos <= size / 2)
		{
			while ((*b)->index != max_idx)
				rb(b);
		}
		else
		{
			while ((*b)->index != max_idx)
				rrb(b);
		}
		pa(a, b);
	}
}
