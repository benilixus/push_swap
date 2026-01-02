/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:22:54 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/02 13:32:57 by oused-da         ###   ########.fr       */
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

static void	run_sort(t_lst **a, t_lst **b)
{
	if (lstsize(*a) == 2)
		sa(a);
	else if (lstsize(*a) == 3)
		sort_three(a);
	else if (lstsize(*a) <= 5)
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
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (c < 2)
		return (0);
	while (i < c)
	{
		if (is_empty_arg(v[i]))
			error_exit(&a, NULL, 0);
		process_arg(&a, v[i]);
		i++;
	}
	if (!a || is_sorted(a))
		return (free_stack(&a), 0);
	run_sort(&a, &b);
	return (0);
}
