/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:27:07 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/28 16:27:08 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	n_count(int argc, char **argv)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (i < argc)
		c += w_count(argv[i++], ' ');
	return (c);
}

int	*fill_array(int argc, char **argv)
{
	int		*array;
	char	**numbers;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	array = malloc(sizeof(int) * n_count(argc, argv));
	if (!array)
		return (NULL);
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (free(array), NULL);
		j = 0;
		while (numbers[j])
			array[k++] = ft_atoi(numbers[j++]);
		i++;
		free_table(numbers, j);
	}
	return (array);
}

int	check_duplicate(int c, char **v)
{
	int	i;
	int	j;
	int	*array;

	if (!check_input(c, v) || !check_overflow(c, v))
		return (0);
	array = fill_array(c, v);
	if (!array)
		return (0);
	i = 0;
	j = 0;
	while (i < n_count(c, v))
	{
		j = i + 1;
		while (j < n_count(c, v))
		{
			if (array[i] == array[j])
				return (free(array), 0);
			j++;
		}
		i++;
	}
	free(array);
	return (1);
}
