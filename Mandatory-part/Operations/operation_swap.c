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

#include "../push_swap.h"

void	sa(t_node **node, int flag)
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
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_node **node, int flag)
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
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_node **node1, t_node **node2)
{
	sa(node1, 0);
	sb(node2, 0);
	write (1, "ss\n", 3);
}
