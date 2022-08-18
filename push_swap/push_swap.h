/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:43:41 by broy              #+#    #+#             */
/*   Updated: 2022/07/22 14:15:19 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	char				*content;
	int					index;
	struct s_stack		*next;
}						t_stack;

typedef struct s_all
{
	t_stack	*a;
	t_stack	*b;
	int		limit;
	int		len;
	char	**input;
	int		check;
}			t_all;

char	**ft_input(char **argv, int *argc, char **input);
int		ft_validate_args(int argc, t_all *all, int *num);
int		ft_is_integer(char *argv);
int		ft_check_duplicates(int argc, int *num, t_all *all);
int		ft_array_is_sorted(int argc, int *num);
void	ft_transform_args(int argc, char **argv, int *num);

void	ft_init_struct(t_all *all, int argc);
void	ft_fill_stack_a(t_all *all, char **bin, int *index);

t_stack	*ft_ps_lstnew(char *bin, int index);
void	ft_ps_lstadd_back(t_stack **lst, t_stack *next);
t_stack	*ft_ps_lstlast(t_stack *lst);
void	ft_ps_lstdelone(t_stack *lst, void (*del)(void *));
t_stack	*ft_ps_lstprevlast(t_stack *lst);
void	ft_ps_lstadd_front(t_stack **lst, t_stack *new);

void	ft_ps_lstclear(t_stack **lst);
void	ft_free_all(t_all *all, int *num, int *index, char **bin);
void	ft_exit_error(t_all *all);

void	ft_del(int *content);

char	*ft_itob(int len, int num);
char	**ft_string_bin(int len, int *num);
int		ft_find_limit(int len);

void	ft_pa(t_all *all);
void	ft_pb(t_all *all);
void	ft_sa(t_all *all);
void	ft_ra(t_all *all);
void	ft_rra(t_all *all);

int		*ft_quick_sort(int len, int *num);
int		*ft_get_index(int len, int *num, int *cpy);
int		*ft_link_index(int len, int *num);

void	ft_push_swap(t_all *all);
void	ft_short_push_swap(t_all *all);
void	ft_long_push_swap(t_all *all);

void	ft_free_array(char **input);
char	*ft_parse(char **av, t_all *all);

#endif
