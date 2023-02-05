/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:25:00 by tguerin           #+#    #+#             */
/*   Updated: 2023/01/31 19:43:26 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_valid_arg(char *string)
{
	int	i;

	if (string[0] != '-')
		return (0);
	i = 1;
	if (string[i] != 'n')
		return (0);
	i++;
	while (string[i])
	{
		if (string[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	get_start_index(char **strings, int size)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (i < size)
	{
		if (is_valid_arg(strings[i]))
			start++;
		else
			break ;
		i++;
	}
	return (start);
}

int	echo(int argc, char **argv, char ***env)
{
	int	start;
	int	i;

	(void)env;
	start = get_start_index(argv + 1, argc - 1);
	i = start + 1;
	while (i < argc)
	{
		if (i - start > 1)
			ft_fprintf(1, " ");
		ft_fprintf(1, "%s", argv[i]);
		i++;
	}
	if (start == 0)
		ft_fprintf(1, "\n");
	return (EXIT_SUCCESS);
}
