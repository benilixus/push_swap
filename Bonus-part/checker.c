/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:09:00 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/30 19:09:01 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

void	do_ops(t_node **a, t_node **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	if (!check_all(argc, argv))
		return (1);
	a = parsing(argc, argv);
	if (!a)
		return (1);
	indexed_node(a);
	b = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!is_valid(line))
			return (free(line),
				write(2, "Error\n", 6), ft_lstclear(&a), ft_lstclear(&b), 1);
		do_ops(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		return (write(1, "OK\n", 3), ft_lstclear(&a), ft_lstclear(&b), 0);
	else
		return (write(1, "KO\n", 3), ft_lstclear(&a), ft_lstclear(&b), 0);
}
