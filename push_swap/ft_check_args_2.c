/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:38:34 by broy              #+#    #+#             */
/*   Updated: 2022/07/27 12:31:50 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_is_digit(char *argv, int i)
{
	if (argv[i] == '-' && !ft_isdigit(argv[i + 1]))
		return (0);
	if (argv[i] == '-' && argv[i + 1] == '\0')
		return (0);
	if (argv[i] != '-' && !ft_isdigit(argv[i]) && argv[i])
		return (0);
	if (argv[i] == '\0')
		return (0);
	return (1);
}

static int	ft_check_is_negative(char *argv, int *neg, int i)
{
	if (argv[i] == '-')
	{
		*neg = 1;
		i++;
	}
	else
		*neg = 0;
	return (i);
}

int	ft_is_integer(char *argv)
{
	int		i;
	int		j;
	long	num;
	int		neg;

	j = 0;
	while (argv[j] == ' ')
		j++;
	if (!ft_check_is_digit(argv, j))
		return (0);
	i = ft_check_is_negative(argv, &neg, 0);
	num = 0;
	while (argv[i + j] != '\0')
	{	
		if (!ft_isdigit(argv[i + j]) && argv[i + j] != ' ')
			return (0);
		num = num * 10 + argv[i + j] - '0';
		if (neg == 1 && - num < INT_MIN)
			return (0);
		if (neg == 0 && num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
