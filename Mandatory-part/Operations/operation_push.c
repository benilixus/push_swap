/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 06:39:12 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/22 06:39:13 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!a || !b || !*b)
		return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	t_node	*tmp;

	if (!b || !a || !*a)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
	write(1, "pb\n", 3);
}
