/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:28:31 by broy              #+#    #+#             */
/*   Updated: 2023/03/05 17:28:34 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_element(int color, int pixels_x, int pixels_y, t_data *data)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	tmp_y = data->minimap_y;
	i = 0;
	while (i < pixels_y)
	{
		j = 0;
		tmp_x = data->minimap_x;
		while (j < pixels_x)
		{
			my_mlx_pixel_put(data, tmp_x, tmp_y, color);
			tmp_x++;
			j++;
		}
		tmp_y++;
		i++;
	}
}

static void	select_minimap_element(int pixels_x, int pixels_y, t_data *data)
{
	char	e;

	e = data->map[data->minimap_height][data->minimap_width];
	if (e == '1')
		draw_element(WALL, pixels_x, pixels_y, data);
	else if (e == '0' || e == 'N' || e == 'E' || e == 'S' || e == 'W')
		draw_element(WALKABLE, pixels_x, pixels_y, data);
	if (data->minimap_height == (int) data->player_y \
		&& data->minimap_width == (int) data->player_x)
		draw_element(PLAYER, pixels_x, pixels_y, data);
}

void	draw_minimap(t_data *data)
{
	int	pixels_x;
	int	pixels_y;

	pixels_x = SCREEN_WIDTH / 100;
	pixels_y = SCREEN_HEIGHT / 100;
	data->minimap_height = 0;
	data->minimap_y = 0;
	while (data->map[data->minimap_height])
	{
		data->minimap_width = 0;
		data->minimap_x = 0;
		while (data->map[data->minimap_height][data->minimap_width])
		{
			select_minimap_element(pixels_x, pixels_y, data);
			data->minimap_x += pixels_x;
			data->minimap_width++;
		}
		data->minimap_y += pixels_y;
		data->minimap_height++;
	}
}
