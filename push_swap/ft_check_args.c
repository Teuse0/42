/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:34:24 by broy              #+#    #+#             */
/*   Updated: 2022/07/02 15:14:27 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_args(int argc, t_all *all, int *num)
{
	int	i;

	i = 0;
	if (all->input[0] == NULL)
	{
		free(num);
		ft_exit_error(all);
	}
	while (i < argc)
	{
		if (ft_is_integer(all->input[i]) == 0)
		{
			free(num);
			ft_exit_error(all);
			return (1);
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicates(int argc, int *num, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (num[i] == num[j])
			{
				free(num);
				ft_exit_error(all);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_transform_args(int argc, char **argv, int *num)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		num[i] = ft_atoi(argv[i]);
		i++;
	}
}

int	ft_array_is_sorted(int len, int *num)
{
	int	i;

	i = 0;
	while (i < len - 1 && num[i] < num[i + 1])
		i++;
	if (i == len - 1)
		return (1);
	else
		return (0);
}
