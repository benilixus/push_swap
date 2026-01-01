/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:22:01 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 13:13:02 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putsrt("rra\n", 1);
}

void	rrb(t_lst **b)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	reverse_rotate(b);
	ft_putsrt("rrb\n", 1);
}

void	rrr(t_lst **a, t_lst **b)
{
	int	rr_a;
	int	rr_b;

	rr_a = 0;
	rr_b = 0;
	if (a && *a && (*a)->next)
	{
		reverse_rotate(a);
		rr_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		reverse_rotate(b);
		rr_b = 1;
	}
	if (rr_a || rr_b)
		ft_putsrt("rrr\n", 1);
}
