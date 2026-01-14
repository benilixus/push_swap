/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:23:19 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 19:20:05 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_index(int *tab, int s)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	while (i < s)
	{
		j = i + 1;
		while (j < s)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static int	*get_arr_index(t_lst *lst, int s)
{
	int	*tab;
	int	i;

	if (!lst)
		return (NULL);
	tab = malloc(sizeof(int) * s);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < s)
	{
		tab[i++] = lst->data;
		lst = lst->next;
	}
	return (sort_index(tab, s));
}

void	indexing(t_lst **lst)
{
	t_lst	*tmp;
	int		*tab;
	int		i;
	int		s;

	if (!lst || !(*lst))
		return ;
	s = lstsize(*lst);
	tab = get_arr_index(*lst, s);
	if (!tab)
		return ;
	tmp = *lst;
	while (tmp)
	{
		i = 0;
		while (i < s)
		{
			if (tmp->data == tab[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
	free(tab);
}
