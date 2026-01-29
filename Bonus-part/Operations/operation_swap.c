/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:07:50 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/21 15:07:51 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa(t_node **node)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!node || !*node || !((*node)->next))
		return ;
	first_node = *node;
	second_node = (*node)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*node = second_node;
}

void	sb(t_node **node)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!node || !*node || !((*node)->next))
		return ;
	first_node = *node;
	second_node = (*node)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*node = second_node;
}

void	ss(t_node **node1, t_node **node2)
{
	sa(node1);
	sb(node2);
}
