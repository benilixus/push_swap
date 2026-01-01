/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:27:15 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 18:20:16 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_split(char **args)
{
	int	i;

	if (!args)
		return (NULL);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}

void	free_stack(t_lst **lst)
{
	t_lst	*tmp;

	if(!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
