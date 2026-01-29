/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:22:19 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/22 11:22:20 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **a)
{
	if (is_sorted(*a))
	{
		return ;
	}
	else if ((*a)->index == 0 && ((*a)->next)->index == 2
		&& ((*a)->next->next)->index == 1)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if ((*a)->index == 1 && ((*a)->next)->index == 0
		&& ((*a)->next->next)->index == 2)
		sa(a, 1);
	else if ((*a)->index == 1 && ((*a)->next)->index == 2
		&& ((*a)->next->next)->index == 0)
		rra(a, 1);
	else if ((*a)->index == 2 && ((*a)->next)->index == 0
		&& ((*a)->next->next)->index == 1)
		ra(a, 1);
	else if ((*a)->index == 2 && ((*a)->next)->index == 1
		&& ((*a)->next->next)->index == 0)
	{
		sa(a, 1);
		rra(a, 1);
	}
}
