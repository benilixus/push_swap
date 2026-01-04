/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:53:05 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/04 14:58:04 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr("sa\n", 1);
}

void	sb(t_lst **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	swap(b);
	ft_putstr("sb\n", 1);
}

void	ss(t_lst **a, t_lst **b)
{
	int	s_a;
	int	s_b;

	s_a = 0;
	s_b = 0;
	if (a && *a && (*a)->next)
	{
		swap(a);
		s_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		swap(b);
		s_b = 1;
	}
	if (s_a || s_b)
		ft_putstr("ss\n", 1);
}
