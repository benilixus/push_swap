/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 11:27:37 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/14 16:16:58 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static int	do_move(t_lst **a, t_lst **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		sa(a);
	else if (!ft_strcmp(move, "sb\n"))
		sb(b);
	else if (!ft_strcmp(move, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(move, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(move, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(move, "ra\n"))
		ra(a);
	else if (!ft_strcmp(move, "rb\n"))
		rb(b);
	else if (!ft_strcmp(move, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(move, "rra\n"))
		rra(a);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(a, b);
	else
		return (1);
	return (0);
}

static t_moves	*get_all_moves(t_lst **a)
{
	char	*line;
	t_moves	*ops;
	t_moves	*node;

	ops = NULL;
	line = get_next_line(0);
	while (line)
	{
		node = new_move(line);
		if (!node)
		{
			free(line);
			free_moves_list(&ops);
			error_exit(a, NULL, 0);
		}
		add_move_back(&ops, node);
		line = get_next_line(0);
	}
	return (ops);
}

static void	read_move(t_lst **a, t_lst **b)
{
	t_moves	*ops;
	t_moves	*curr;

	ops = get_all_moves(a);
	curr = ops;
	while (curr)
	{
		if (do_move(a, b, curr->move))
		{
			free_moves_list(&ops);
			free_stack(b);
			error_exit(a, NULL, 0);
		}
		curr = curr->next;
	}
	if (is_sorted(*a) && !(*b))
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
	free_moves_list(&ops);
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
	if (!a)
		return (0);
	read_move(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
