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

#include "../checker.h"

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
