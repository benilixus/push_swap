/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:22:54 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/02 10:30:36 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_lst *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_lst **a)
{
	int	top;
	int	mid;
	int	bot;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	top = (*a)->data;
	mid = (*a)->next->data;
	bot = (*a)->next->next->data;
	if (top > mid && top > bot)
		ra(a);
	else if (mid > top && mid > bot)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

static void	check(t_lst **a, t_lst **b)
{
	if (lstsize(*a) == 2)
		sa(a);
	else if (lstsize(*a) == 3)
		sort_three(a);
	else if (lstsize(*a) == 5)
		sort_five(a, b);
	else
	{
		indexing(a);
		butterfly(a, b);
		butterfly_return(a, b);
	}
	free_stack(a);
	free_stack(b);
}

int	main(int c, char **v)
{
	t_lst	*a;
	t_lst	*b;
	char	**args;
	int		use_split;

	a = NULL;
	b = NULL;
	use_split = 0;
	if (c < 2)
		return (0);
	if (c == 2)
	{
		args = ft_split(v[1]);
		use_split = 1;
	}
	else
		args = v + 1;
	fill_stack(&a, args, use_split);
	if (use_split)
		free_split(args);
	if (!a || is_sorted(a))
		return (free_stack(&a), 0);
	if (!is_sorted(a))
		check(&a, &b);
	return (0);
}
