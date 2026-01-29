/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:25:52 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/26 17:25:55 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_down(t_node **a, t_node **b, unsigned int chunk_size)
{
	unsigned int	i;

	i = 0;
	while (*a)
	{
		while (((*a)->index) > ((chunk_size + i)))
			ra(a, 1);
		if (((*a)->index) <= (i))
		{
			pb(b, a);
			rb(b, 1);
		}
		else
			pb(b, a);
		i++;
	}
}

void	push_back(t_node **b, t_node **a)
{
	t_node	*max;

	while (*b)
	{
		max = find_max(*b);
		while (((*b)->index) != (max->index))
		{
			if (find_pos(*b, max) > (ft_lstsize(*b) / 2))
				rrb(b, 1);
			else
				rb(b, 1);
		}
		pa(a, b);
	}
}
