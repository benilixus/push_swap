/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:31:32 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/29 23:31:35 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ops(t_node **a, t_node **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four (a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size > 5 && size <= 100)
	{
		push_down(a, b, 14);
		push_back(b, a);
	}
	else if (size > 100)
	{
		push_down(a, b, 35);
		push_back(b, a);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	if (argc < 2)
		return (0);
	if (!check_all(argc, argv))
		return (0);
	a = parsing(argc, argv);
	if (!a)
		return (1);
	indexed_node(a);
	if (is_sorted(a))
		return (ft_lstclear(&a), 0);
	b = NULL;
	size = ft_lstsize(a);
	do_ops(&a, &b, size);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
