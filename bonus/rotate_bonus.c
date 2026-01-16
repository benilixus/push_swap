/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:36:13 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/14 14:54:49 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	rb(t_lst **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	rotate(b);
}

void	rr(t_lst **a, t_lst **b)
{
	if (a && *a && (*a)->next)
	{
		rotate(a);
	}
	if (b && *b && (*b)->next)
	{
		rotate(b);
	}
}
