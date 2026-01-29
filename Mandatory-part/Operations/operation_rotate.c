/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:35:52 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/22 08:35:53 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a, int flag)
{
	t_node	*tmp;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int flag)
{
	t_node	*tmp;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
