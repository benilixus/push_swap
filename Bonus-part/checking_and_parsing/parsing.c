/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:37:09 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/21 15:13:40 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_node	*parsing(int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;
	t_node	*head;
	t_node	*new;

	head = NULL;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (ft_lstclear(&head), NULL);
		while (numbers[++j])
		{
			new = ft_lstnew(ft_atoi(numbers[j]));
			if (!new)
				return ((free_table(numbers, w_count(argv[i], ' '))),
					ft_lstclear(&head), NULL);
			ft_lstadd_back(&head, new);
		}
		free_table(numbers, j);
	}
	return (head);
}
