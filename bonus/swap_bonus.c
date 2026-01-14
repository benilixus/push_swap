/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:53:05 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/14 14:55:04 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap(t_lst **lst)
{
	int	data;
	int	index;

	data = (*lst)->data;
	index = (*lst)->index;
	(*lst)->data = (*lst)->next->data;
	(*lst)->index = (*lst)->next->index;
	(*lst)->next->data = data;
	(*lst)->next->index = index;
}

void	sa(t_lst **a)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	swap(a);
}

void	sb(t_lst **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	swap(b);
}

void	ss(t_lst **a, t_lst **b)
{
	if (a && *a && (*a)->next)
	{
		swap(a);
	}
	if (b && *b && (*b)->next)
	{
		swap(b);
	}
}
