/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:56:24 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/21 00:56:25 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_array(int *array, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*filling_array(t_node *node)
{
	int		i;
	int		n;
	int		*array;
	t_node	*head;

	i = 0;
	n = ft_lstsize(node);
	array = malloc(sizeof(int) * n);
	if (!array)
		return (NULL);
	head = node;
	while (i < n)
	{
		array[i] = head->number;
		head = head->next;
		i++;
	}
	sort_array(array, n);
	return (array);
}

void	indexing_nodes(t_node *node, int *array)
{
	int	i;
	int	n;

	n = ft_lstsize(node);
	while (node)
	{
		i = 0;
		while (i < n)
		{
			if (((node)->number) == array[i])
			{
				(node)->index = i;
				break ;
			}
			i++;
		}
		(node) = (node)->next;
	}
}

void	indexed_node(t_node *node)
{
	int	*array;

	array = filling_array(node);
	if (!array)
		return ;
	indexing_nodes(node, array);
	free(array);
}
