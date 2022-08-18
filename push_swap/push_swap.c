/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:59:58 by broy              #+#    #+#             */
/*   Updated: 2022/08/16 15:31:07 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_struct(t_all *all, int argc)
{
	all->a = NULL;
	all->b = NULL;
	all->len = argc;
}

void	ft_fill_stack_a(t_all *all, char **bin, int *index)
{
	int	i;

	if (all->len)
	{
		i = 0;
		all->a = ft_ps_lstnew(bin[i], index[i]);
		while (i < all->len - 1)
		{
			i++;
			ft_ps_lstadd_back(&all->a, ft_ps_lstnew(bin[i], index[i]));
		}
	}
}

void	ft_push_swap(t_all *all)
{
	if (all->len <= 5)
		ft_short_push_swap(all);
	else
		ft_long_push_swap(all);
}

static int	*main_2(t_all *all, int argc, int *num)
{
	char	**bin;
	int		*index;

	num = malloc(sizeof(int) * argc);
	if (!num)
		exit(EXIT_FAILURE);
	ft_validate_args(argc, all, num);
	ft_transform_args(argc, all->input, num);
	ft_check_duplicates(argc, num, all);
	if (ft_array_is_sorted(argc, num))
	{
		free(num);
		num = NULL;
		return (num);
	}
	index = ft_link_index(argc, num);
	bin = ft_string_bin(argc, index);
	ft_init_struct(all, argc);
	ft_fill_stack_a(all, bin, index);
	if (argc == 2)
		ft_ra(all);
	else
		ft_push_swap(all);
	ft_free_all(all, num, index, bin);
	return (num);
}

int	main(int argc, char **argv)
{
	t_all		all;
	int			*num;
	char		*str;

	num = 0;
	all.input = NULL;
	all.check = 1;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
		all.input = ft_input(argv, &argc, all.input);
	else
	{
		argv++;
		argc = 0;
		str = ft_parse(argv, &all);
		all.input = ft_split(str, ' ');
		while (all.input[argc])
			argc++;
		free(str);
	}
	num = main_2(&all, argc, num);
	if (all.check == 1)
		ft_free_array(all.input);
	return (0);
}
