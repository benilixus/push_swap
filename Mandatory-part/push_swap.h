/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:05:17 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/30 00:09:54 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				number;
	unsigned int	index;
	struct s_node	*next;

}					t_node;

int					position_of_zero(t_node *a);
int					position_of_one(t_node *a);
int					ft_strlen(char *str);
int					w_count(char const *str, char c);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
void				free_table(char **table, int count);

t_node				*parsing(int argc, char **argv);

t_node				*ft_lstnew(int number);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_back(t_node **lst, t_node *new);
t_node				*ft_lstlast(t_node *lst);
int					ft_lstsize(t_node *lst);
void				ft_lstclear(t_node **lst);
t_node				*ft_second_last(t_node *lst);

t_node				*find_max(t_node *a);
int					check_input(int argc, char **argv);
int					check_overflow(int argc, char **argv);
int					check_duplicate(int argc, char **argv);
int					check_all(int c, char **v);
int					find_pos(t_node *a, t_node *needle);

int					is_sorted(t_node *node);
void				indexed_node(t_node *node);

void				sa(t_node **a, int i);
void				sb(t_node **b, int i);
void				ss(t_node **a, t_node **b);

void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);

void				ra(t_node **a, int flag);
void				rb(t_node **b, int flag);
void				rr(t_node **a, t_node **b);

void				rra(t_node **a, int flag);
void				rrb(t_node **b, int flag);
void				rrr(t_node **a, t_node **b);

void				sort_three(t_node **a);
void				sort_five(t_node **a, t_node **b);
void				sort_four(t_node **a, t_node **b);
void				push_down(t_node **a, t_node **b, unsigned int chunksize);
void				push_back(t_node **b, t_node **a);

#endif
