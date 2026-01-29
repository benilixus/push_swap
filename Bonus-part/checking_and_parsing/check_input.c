/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:21:52 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/27 21:22:01 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	input_helper(char **numbers, char *arg)
{
	int	j;
	int	k;

	j = 0;
	while (numbers[j])
	{
		k = 0;
		while (numbers[j][k])
		{
			if (k == 0 && (numbers[j][k] == '-' || numbers[j][k] == '+'))
			{
				k++;
				if (ft_strlen(numbers[j]) == 1)
					return (free_table(numbers, w_count(arg, ' ')), 0);
			}
			if (!(numbers[j][k] >= '0' && numbers[j][k] <= '9'))
				return (free_table(numbers, w_count(arg, ' ')), 0);
			k++;
		}
		j++;
	}
	return (free_table(numbers, j), 1);
}

int	check_input(int argc, char **argv)
{
	char	**numbers;
	int		i;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (0);
		if (!w_count(argv[i], ' '))
			return (free(numbers), 0);
		if (!input_helper(numbers, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
