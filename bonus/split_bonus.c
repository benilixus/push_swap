/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:36:18 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/14 14:54:55 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	count_args(char *s)
{
	int	i;
	int	args;

	i = 0;
	args = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		while (s[i] && s[i] != ' ')
			i++;
		if ((s[i] == '\0' || s[i] == ' ') && s[i - 1] != ' ')
		{
			args++;
			if (s[i] == '\0')
				break ;
			i++;
		}
	}
	return (args);
}

static void	extract_len(int *tab, char *s)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == ' ')
			i++;
		while (s[i] && s[i] != ' ')
		{
			i++;
			len++;
		}
		if ((s[i] == '\0' || s[i] == ' ') && s[i - 1] != ' ')
		{
			tab[j++] = len;
			if (s[i] == '\0')
				break ;
			i++;
		}
	}
}

static int	*length(char *s, int size)
{
	int	*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	extract_len(tab, s);
	return (tab);
}

static char	**sep_args(char *s, char **args, int *tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		args[j] = ft_calloc(tab[j] + 1, sizeof(char));
		if (!args[j])
		{
			free(tab);
			return (free_split(args));
		}
		while (s[i] && s[i] != ' ')
			args[j][k++] = s[i++];
		args[j++][k] = 0;
	}
	args[j] = NULL;
	return (args);
}

char	**ft_split(char *s)
{
	char	**args;
	int		params;
	int		*tab;

	params = count_args(s);
	args = ft_calloc(params + 1, sizeof(char *));
	if (!args)
		return (NULL);
	if (params > 0)
	{
		tab = length(s, params);
		if (!tab)
		{
			free(args);
			return (NULL);
		}
		args = sep_args(s, args, tab);
		if (!args)
			return (free(tab), NULL);
		free(tab);
	}
	return (args);
}
