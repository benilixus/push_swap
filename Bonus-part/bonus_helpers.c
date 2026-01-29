/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:44:33 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/30 21:44:34 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valid(char *line)
{
	int	flag;

	flag = 0;
	if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n")
		|| !ft_strcmp(line, "rr\n") || !ft_strcmp(line, "rra\n")
		|| !ft_strcmp(line, "rrb\n") || !ft_strcmp(line, "rrr\n")
		|| !ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pb\n"))
		flag = 1;
	return (flag);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
