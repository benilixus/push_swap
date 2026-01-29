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

#include "../checker.h"

void	ra(t_node **a)
{
	t_node	*tmp;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
}

void	rb(t_node **b)
{
	t_node	*tmp;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}
