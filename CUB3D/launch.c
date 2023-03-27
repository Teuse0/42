/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:01:00 by broy              #+#    #+#             */
/*   Updated: 2023/03/03 17:01:01 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.len + x * (data->img.bits / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	draw_ceiling(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT / 2)
			my_mlx_pixel_put(data, i, j, data->ceilling);
		i++;
	}
}

void	draw_floor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2 - 1;
		while (++j < SCREEN_HEIGHT)
			my_mlx_pixel_put(data, i, j, data->floor);
		i++;
	}
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->rgb[i])
	{
		free(data->rgb[i]);
		i++;
	}
	free(data->rgb);
	i = 0;
	while (data->xpm[i])
	{
		free(data->xpm[i]);
		i++;
	}
	free(data->xpm);
}

int	ft_exit(t_data *data)
{
	ft_free_data(data);
	ft_free_map(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}

int	ft_key(int key, t_data *data)
{
	if (key == ESC)
		ft_exit(data);
	return (0);
}

int	ft_launch(t_data *data)
{
	void	*img;
	char	*addr;

	ft_init(data);

	data->player_x = 5;
	data->player_y = 4;

	img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img.ptr = img;
	addr = mlx_get_data_addr(data->img.ptr, &data->img.bits,
			&data->img.len, &data->img.endian);

	data->img.addr = addr;
	draw_floor(data);
	draw_ceiling(data);
	//raycast_loop(data);
	draw_minimap(data);
	/*hooks();
	data->var.frame_time = 16 / 1000.0;
	data->var.move_speed = data->var.frame_time * 5.0;
	data->var.rot_speed = data->var.frame_time * 3.0;*/
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->img.ptr);
	mlx_key_hook(data->win, ft_key, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
	return (0);
}
