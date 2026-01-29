/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:12:35 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/30 00:10:29 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node *node)
{
	unsigned int	i;

	i = 0;
	while (node)
	{
		if (i != node->index)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	position_of_zero(t_node *a)
{
	int	i;

	i = 0;
	while ((a->index) != 0)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int	position_of_one(t_node *a)
{
	int	i;

	i = 0;
	while ((a->index) != 1)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_node	*find_max(t_node *a)
{
	t_node	*max_node;

	if (!a)
		return (NULL);
	max_node = a;
	while (a)
	{
		if (a->index > max_node->index)
			max_node = a;
		a = a->next;
	}
	return (max_node);
}
