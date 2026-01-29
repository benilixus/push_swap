/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:26:47 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/29 23:35:40 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_four(t_node **a, t_node **b)
{
	if (is_sorted(*a))
		return ;
	if (position_of_zero(*a) > (ft_lstsize(*a) / 2))
		while (((*a)->index) != 0)
			rra(a, 1);
	else
		while (((*a)->index) != 0)
			ra(a, 1);
	if (is_sorted(*a))
		return ;
	pb(b, a);
	indexed_node(*a);
	if (!(is_sorted(*a)))
		sort_three(a);
	if ((is_sorted(*b)))
		sb(b, 1);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	if (is_sorted(*a))
		return ;
	if (position_of_zero(*a) > (ft_lstsize(*a) / 2))
		while (((*a)->index) != 0)
			rra(a, 1);
	else
		while (((*a)->index) != 0)
			ra(a, 1);
	pb(b, a);
	if (position_of_one(*a) > (ft_lstsize(*a) / 2))
		while (((*a)->index) != 1)
			rra(a, 1);
	else
		while (((*a)->index) != 1)
			ra(a, 1);
	pb(b, a);
	indexed_node(*a);
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (!(is_sorted(*a)))
		sa(a, 1);
	if ((is_sorted(*b)))
		sb(b, 1);
	pa(a, b);
	pa(a, b);
}
