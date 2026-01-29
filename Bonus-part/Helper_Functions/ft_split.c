/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:37:27 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/08 09:18:50 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	w_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

void	free_table(char **table, int count)
{
	while (count--)
		free(table[count]);
	free(table);
}

char	*ft_strndup(char const *str, int c)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(c + 1);
	if (!dup)
		return (NULL);
	while (i < c)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	fill_table(char **table, char const *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			table[index] = ft_strndup(s + j, i - j);
			if (!table[index])
				return (free_table(table, index), -1);
			index++;
		}
	}
	return (index);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		count;

	if (!s)
		return (NULL);
	table = malloc((w_count(s, c) + 1) * sizeof(char *));
	if (!table)
		return (NULL);
	count = fill_table(table, s, c);
	if (count == -1)
	{
		free(table);
		return (NULL);
	}
	table[count] = NULL;
	return (table);
}
