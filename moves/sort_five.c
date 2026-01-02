/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:22:46 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/02 10:25:45 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_lst *lst)
{
	int	min;

	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

static void	move_to_top(t_lst **a, int target)
{
	int		pos;
	t_lst	*tmp;
	int		size;

	tmp = *a;
	pos = 0;
	while (tmp && tmp->data != target)
	{
		pos++;
		tmp = tmp->next;
	}
	size = lstsize(*a);
	if (pos <= size / 2)
	{
		while ((*a)->data != target)
			ra(a);
	}
	else
	{
		while ((*a)->data != target)
			rra(a);
	}
}

void	sort_five(t_lst **a, t_lst **b)
{
	int	min;

	min = find_min(*a);
	move_to_top(a, min);
	pb(a, b);
	min = find_min(*a);
	move_to_top(a, min);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
