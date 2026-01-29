/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:13:56 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/20 23:13:57 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while ((lst->next))
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_node	*ft_lstnew(int number)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*next;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

int	ft_lstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int		main(void)
// {
// 	t_node	*number1 = ft_lstnew(10);
// 	printf("%d\n", number1 -> number);
// 	ft_lstclear(&number1);
// }