/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:52:05 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 13:12:58 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_lst **src, t_lst **dst)
{
	t_lst	*tmp;
	int		data;
	int		index;

	if (!src || !(*src))
		return ;
	data = (*src)->data;
	index = (*src)->index;
	addfront(dst, newlst(data, index));
	tmp = (*src);
	if ((*src)->next)
	{
		(*src) = (*src)->next;
		(*src)->prev = NULL;
	}
	else
		(*src) = NULL;
	free(tmp);
}

void	pa(t_lst **a, t_lst **b)
{
	if (!b || !(*b))
		return ;
	push(b, a);
	ft_putsrt("pa\n", 1);
}

void	pb(t_lst **a, t_lst **b)
{
	if (!a || !(*a))
		return ;
	push(a, b);
	ft_putsrt("pb\n", 1);
}
