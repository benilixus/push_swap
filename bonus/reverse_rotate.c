/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:22:01 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/04 13:45:15 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_lst **lst)
{
	t_lst	*last;
	t_lst	*fst;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	last = lstlast(*lst);
	fst = (*lst);
	last->prev->next = NULL;
	fst->prev = last;
	last->next = fst;
	last->prev = NULL;
	(*lst) = last;
}

void	rra(t_lst **a)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	reverse_rotate(a);
}

void	rrb(t_lst **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	reverse_rotate(b);
}

void	rrr(t_lst **a, t_lst **b)
{
	if (a && *a && (*a)->next)
		reverse_rotate(a);
	if (b && *b && (*b)->next)
		reverse_rotate(b);
}
