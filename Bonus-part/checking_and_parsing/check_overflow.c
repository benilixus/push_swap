/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:09:30 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/28 15:09:31 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	overflow_helper(char **numbers, int size)
{
	long	n;
	int		s;
	int		j;
	int		k;

	j = -1;
	while (numbers[++j])
	{
		k = 0;
		n = 0;
		s = 1;
		if (numbers[j][k] == '-' || numbers[j][k] == '+')
			if (numbers[j][k++] == '-')
				s *= (-1);
		while (numbers[j][k])
		{
			n = n * 10 + (numbers[j][k++] - '0');
			if ((s * n) > 2147483647L || (s * n) < -2147483648L)
				return (free_table(numbers, size), 0);
		}
	}
	free_table(numbers, size);
	return (1);
}

int	check_overflow(int argc, char **argv)
{
	int		i;
	int		size;
	char	**numbers;

	if (!check_input(argc, argv))
		return (0);
	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (free(numbers), 0);
		size = w_count(argv[i], ' ');
		if (!overflow_helper(numbers, size))
			return (0);
		i++;
	}
	return (1);
}
