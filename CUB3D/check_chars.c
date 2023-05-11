/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:44:04 by broy              #+#    #+#             */
/*   Updated: 2023/04/19 18:44:05 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_vectors(int x, int y, t_data *data)
{
	data->var.pos_x = x + 0.5;
	data->var.pos_y = y + 0.5;
	if (data->map[y][x] == 'N')
	{
		data->var.dir_x = 0;
		data->var.dir_y = -1;
		data->var.plane_x = 0.66;
		data->var.plane_y = 0;
	}
	else if (data->map[y][x] == 'S')
	{
		data->var.dir_x = 0;
		data->var.dir_y = 1;
		data->var.plane_x = -0.66;
		data->var.plane_y = 0;
	}
	else if (data->map[y][x] == 'E')
	{
		data->var.dir_x = 1;
		data->var.dir_y = 0;
		data->var.plane_x = 0;
		data->var.plane_y = 0.66;
	}
	else if (data->map[y][x] == 'W')
	{
		data->var.dir_x = -1;
		data->var.dir_y = 0;
		data->var.plane_x = 0;
		data->var.plane_y = -0.66;
	}
}

int	check_chars(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_strchr(" 10NSEW\n", data->map[i][j]))
				return (0);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				init_vectors(j, i, data);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
