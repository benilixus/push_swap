/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <oused-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:51:55 by oused-da          #+#    #+#             */
/*   Updated: 2026/01/04 15:27:09 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define SIZE_MAX __SIZE_MAX__

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
void	free_stack(t_lst **lst);
// print
void	ft_putstr(char *s, int fd);
int		is_digit(char c);
//parsing
long	ft_atol(const char *n);
char	**ft_split(char *s);
char	**free_split(char **args);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_ovflow(long n);
int		check_dup(t_lst *a, int n);
int		all_digits(char *args);
void	process_arg(t_lst **a, char *str);
int		is_empty_arg(char *s);
//Error
void	error_exit(t_lst **a, char **args, int use_split);
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
//indexing
void	indexing(t_lst **lst);
void	butterfly(t_lst **a, t_lst **b);
void	butterfly_return(t_lst **a, t_lst **b);
void	sort_five(t_lst **a, t_lst **b);
void	sort_three(t_lst **a);

#endif
