/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:35:52 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/22 09:35:53 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rra(t_node **a)
{
	t_node	*new_last;
	t_node	*last;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	new_last = ft_second_last(*a);
	last = ft_lstlast(*a);
	new_last->next = NULL;
	ft_lstadd_front(a, last);
}

void	rrb(t_node **b)
{
	t_node	*new_last;
	t_node	*last;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	new_last = ft_second_last(*b);
	last = ft_lstlast(*b);
	new_last->next = NULL;
	ft_lstadd_front(b, last);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}
