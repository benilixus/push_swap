/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:51:55 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/01 13:12:49 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_lst
{
	int				data;
	int				index;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;
// lst
t_lst	*lstlast(t_lst *lst);
t_lst	*newlst(int data, int index);
void	addback(t_lst **lst, t_lst *new);
void	addfront(t_lst **lst, t_lst *new);
int		lstsize(t_lst *lst);
// print
void	ft_putsrt(char *s, int fd)
//swap
void	sa(t_lst **a);
void	sb(t_lst **b);
void	ss(t_lst **a, t_lst **b);
//push
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
//reverse rotate
void	rra(t_lst **a);
void	rrb(t_lst **b);
void	rrr(t_lst **a, t_lst **b);
//rotate
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rr(t_lst **a, t_lst **b);
#endif
