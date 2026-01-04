/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:27:15 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/04 14:55:21 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	error_exit(t_lst **a, char **args, int use_split)
{
	free_stack(a);
	if (use_split)
		free_split(args);
	ft_putstr("Error\n", 2);
	exit(1);
}
