/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rush02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 09:47:30 by rgallois          #+#    #+#             */
/*   Updated: 2022/03/06 19:00:52 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_simple(char *nbr)
{
	t_dict	*dict;

	if (!ft_arg_error(nbr))
	{
		ft_putstr("Error\n");
		return (0);
	}
	dict = ft_parser(PATH);
	if (ft_print(dict, nbr))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (1);
}

int	ft_double(char *path, char *nbr)
{
	t_dict	*dict;

	if (!ft_arg_error(nbr) || !ft_path_error(path))
	{
		ft_putstr("Error\n");
		return (0);
	}
	dict = ft_parser(path);
	if (ft_print(dict, nbr))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_simple(argv[1]))
			return (1);
	}
	else if (argc == 3)
	{
		if (!ft_double(argv[1], argv[2]))
			return (1);
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	write(1, "\n", 1);
	return (0);
}
