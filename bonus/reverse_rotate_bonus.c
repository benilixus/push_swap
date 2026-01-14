/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:22:01 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/14 14:54:44 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
