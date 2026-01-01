/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:52:19 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 16:28:03 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*newlst(int data, int index)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = index;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	addback(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{	
		(*lst) = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
	new->prev = last;
}

void	addfront(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	new->prev = NULL;
	(*lst) = new;
}

int	lstsize(t_lst *lst)
{
	int	s;

	s = 0;
	while (lst)
	{
		s++;
		lst = lst->next;
	}
	return (s);
}
