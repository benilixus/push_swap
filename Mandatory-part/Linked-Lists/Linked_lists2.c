/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Linked_lists2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 06:43:12 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/22 06:43:16 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_node	*ft_second_last(t_node *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while ((lst->next)->next)
		lst = lst->next;
	return (lst);
}
