/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:18:18 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/12/30 21:18:21 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				number;
	unsigned int	index;
	struct s_node	*next;
}					t_node;

int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);
int					is_valid(char *line);

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

int					check_input(int argc, char **argv);
int					check_overflow(int argc, char **argv);
int					check_duplicate(int argc, char **argv);
int					check_all(int c, char **v);

int					is_sorted(t_node *node);
void				indexed_node(t_node *node);

void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);

void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);

void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

#endif
