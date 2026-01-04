/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:36:13 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/04 14:58:15 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_lst **lst)
{
	t_lst	*last;
	t_lst	*fst;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	last = lstlast(*lst);
	fst = (*lst);
	(*lst) = (*lst)->next;
	(*lst)->prev = NULL;
	last->next = fst;
	fst->prev = last;
	fst->next = NULL;
}

void	ra(t_lst **a)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	rotate(a);
	ft_putstr("ra\n", 1);
}

void	rb(t_lst **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	rotate(b);
	ft_putstr("rb\n", 1);
}

void	rr(t_lst **a, t_lst **b)
{
	int	r_a;
	int	r_b;

	r_a = 0;
	r_b = 0;
	if (a && *a && (*a)->next)
	{
		rotate(a);
		r_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		rotate(b);
		r_b = 1;
	}
	if (r_a || r_b)
		ft_putstr("rr\n", 1);
}
