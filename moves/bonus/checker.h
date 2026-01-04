#ifndef CHECKER_H
# define CHECKER_H

# include "./gnl/get_next_line.h"
# define SIZE_MAX __SIZE_MAX__

typedef struct s_lst
{
	int				data;
	int				index;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

t_lst	*newlst(int data, int index);
void	addback(t_lst **lst, t_lst *new);
void	addfront(t_lst **lst, t_lst *new);
void	free_stack(t_lst **lst);
t_lst	*lstlast(t_lst *lst);

void	ft_putstr(char *s, int fd);
int		is_digit(char c);

long	ft_atol(const char *n);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *s);
char	**free_split(char **args);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_ovflow(long n);
int		check_dup(t_lst *a, int n);
int		all_digits(char *args);
void	process_arg(t_lst **a, char *str);
int		is_empty_arg(char *s);

void	error_exit(t_lst **a, char **args, int use_split);

void	sa(t_lst **a);
void	sb(t_lst **b);
void	ss(t_lst **a, t_lst **b);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
void	rra(t_lst **a);
void	rrb(t_lst **b);
void	rrr(t_lst **a, t_lst **b);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rr(t_lst **a, t_lst **b);

#endif
