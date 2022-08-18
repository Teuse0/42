/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:58:02 by broy              #+#    #+#             */
/*   Updated: 2022/07/26 12:40:03 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_long_push_swap(t_all *all)
{
	int	i;

	all->limit = ft_find_limit(all->len);
	i = 0;
	while (all->limit >= 0)
	{
		while (i < all->len)
		{
			if (all->a->content[all->limit] == '0')
				ft_pb(all);
			else
				ft_ra(all);
			i++;
		}
		while (all->b)
			ft_pa(all);
		all->limit--;
		i = 0;
	}
}

static int	ft_pos_0_greater_pos_1(int pos_0, int pos_1, int pos_2, t_all *all)
{
	if (pos_1 > pos_2)
	{
		ft_sa(all);
		ft_rra(all);
		return (1);
	}
	if (pos_0 > pos_2)
	{
		ft_ra(all);
		return (1);
	}
	else
	{
		ft_sa(all);
		return (1);
	}
	return (0);
}

static int	ft_pos_0_lower_pos_1(int pos_0, int pos_2, t_all *all)
{
	if (pos_0 > pos_2)
	{
		ft_rra(all);
		return (1);
	}
	else
	{
		ft_sa(all);
		ft_ra(all);
		return (1);
	}
	return (0);
}

static int	ft_three_numbers(t_all *all)
{
	int	pos_0;
	int	pos_1;
	int	pos_2;

	pos_0 = all->a->index;
	pos_1 = all->a->next->index;
	pos_2 = all->a->next->next->index;
	if (pos_0 < pos_1 && pos_1 < pos_2)
		return (1);
	if (pos_0 > pos_1)
	{
		ft_pos_0_greater_pos_1(pos_0, pos_1, pos_2, all);
		return (1);
	}
	else
	{
		ft_pos_0_lower_pos_1(pos_0, pos_2, all);
		return (1);
	}
	return (0);
}

void	ft_short_push_swap(t_all *all)
{
	if (all->len > 3)
	{
		while (all->a->index != 0)
			ft_ra(all);
		ft_pb(all);
		if (all->len == 5)
		{
			while (all->a->index != 1)
				ft_ra(all);
			ft_pb(all);
		}
	}
	ft_three_numbers(all);
	if (all->len == 4)
		ft_pa(all);
	if (all->len == 5)
	{
		ft_pa(all);
		ft_pa(all);
	}
}
