/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:35:21 by broy              #+#    #+#             */
/*   Updated: 2023/03/02 16:35:23 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_args(char *file)
{
	if (!file || !file[0])
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	printf("av = %s\n", av[1]);
	printf("ac = %d\n", ac);
	if (ac == 2 && ft_check_args(av[1]))
	{
		ft_parse(av[1], &data);
		write(1, "YES\n", 4);
	}
	return (0);
}
