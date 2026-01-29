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

#include "../push_swap.h"

void	rra(t_node **a, int flag)
{
	t_node	*new_last;
	t_node	*last;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	new_last = ft_second_last(*a);
	last = ft_lstlast(*a);
	new_last->next = NULL;
	ft_lstadd_front(a, last);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int flag)
{
	t_node	*new_last;
	t_node	*last;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	new_last = ft_second_last(*b);
	last = ft_lstlast(*b);
	new_last->next = NULL;
	ft_lstadd_front(b, last);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
