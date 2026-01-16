/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:40:21 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/14 15:44:08 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_moves	*new_move(char *ope)
{
	t_moves	*new;

	new = malloc(sizeof(t_moves));
	if (!new)
		return (NULL);
	new->move = ope;
	new->next = NULL;
	return (new);
}

void	add_move_back(t_moves **lst, t_moves *new)
{
	t_moves	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	free_moves_list(t_moves **lst)
{
	t_moves	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->move);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	is_move(char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		return (1);
	else if (!ft_strcmp(move, "sb\n"))
		return (1);
	else if (!ft_strcmp(move, "ss\n"))
		return (1);
	else if (!ft_strcmp(move, "pa\n"))
		return (1);
	else if (!ft_strcmp(move, "pb\n"))
		return (1);
	else if (!ft_strcmp(move, "ra\n"))
		return (1);
	else if (!ft_strcmp(move, "rb\n"))
		return (1);
	else if (!ft_strcmp(move, "rr\n"))
		return (1);
	else if (!ft_strcmp(move, "rra\n"))
		return (1);
	else if (!ft_strcmp(move, "rrb\n"))
		return (1);
	else if (!ft_strcmp(move, "rrr\n"))
		return (1);
	else
		return (0);
}

void	ft_free(char *line, t_moves **ops, t_lst **a)
{
	free(line);
	get_next_line(-1);
	free_moves_list(ops);
	error_exit(a, NULL, 0);
}
