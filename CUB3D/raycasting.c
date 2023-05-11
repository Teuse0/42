/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:03:05 by broy              #+#    #+#             */
/*   Updated: 2023/04/18 17:03:06 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_delta_dist(t_data *data)
{
	if (data->var.ray_x == 0)
		data->var.delta_dist_x = 1e30;
	else
		data->var.delta_dist_x = fabs(1 / data->var.ray_x);
	if (data->var.ray_y == 0)
		data->var.delta_dist_y = 1e30;
	else
		data->var.delta_dist_y = fabs(1 / data->var.ray_y);
}

void	set_box_pos(t_data *data)
{
	data->var.map_x = (int) data->var.pos_x;
	data->var.map_y = (int) data->var.pos_y;
	data->var.hit = 0;
}

void	calc_ray_pos_and_dir(int x, t_data *data)
{
	data->var.cam_x = 2 * x / (double) SCREEN_WIDTH - 1;
	data->var.ray_x = data->var.dir_x + \
							data->var.plane_x * data->var.cam_x;
	data->var.ray_y = data->var.dir_y + \
							data->var.plane_y * data->var.cam_x;
}

void	calc_step_and_side_dist(t_data *data)
{
	if (data->var.ray_x < 0)
	{
		data->var.step_x = -1;
		data->var.side_dist_x = (data->var.pos_x - data->var.map_x) \
								* data->var.delta_dist_x;
	}
	else
	{
		data->var.step_x = 1;
		data->var.side_dist_x = (data->var.map_x + 1.0 \
			- data->var.pos_x) * data->var.delta_dist_x;
	}
	if (data->var.ray_y < 0)
	{
		data->var.step_y = -1;
		data->var.side_dist_y = (data->var.pos_y - data->var.map_y) \
								* data->var.delta_dist_y;
	}
	else
	{
		data->var.step_y = 1;
		data->var.side_dist_y = (data->var.map_y + 1.0 \
			- data->var.pos_y) * data->var.delta_dist_y;
	}
}

void	set_texture(t_data *data)
{
	if (data->var.side == 0)
	{
		if (data->var.map_x > data->var.pos_x)
			data->var.tex_num = 1;
		else
			data->var.tex_num = 3;
	}
	else
	{
		if (data->var.map_y > data->var.pos_y)
			data->var.tex_num = 2;
		else
			data->var.tex_num = 0;
	}
}

void	dda(t_data *data)
{
	while (data->var.hit == 0)
	{
		if (data->var.side_dist_x < data->var.side_dist_y)
		{
			data->var.side_dist_x += data->var.delta_dist_x;
			data->var.map_x += data->var.step_x;
			data->var.side = 0;
		}
		else
		{
			data->var.side_dist_y += data->var.delta_dist_y;
			data->var.map_y += data->var.step_y;
			data->var.side = 1;
		}
		if (data->map[data->var.map_y][data->var.map_x] == '1')
		{
			data->var.hit = 1;
			set_texture(data);
		}
	}
}

void	calc_dist_perp(t_data *data)
{
	if (data->var.side == 0)
		data->var.perp_wall_dist = \
			data->var.side_dist_x - data->var.delta_dist_x;
	else
		data->var.perp_wall_dist = \
			data->var.side_dist_y - data->var.delta_dist_y;
}

void	calc_vertical_line_height(t_data *data)
{
	data->var.line_height = \
		(int)(SCREEN_HEIGHT / data->var.perp_wall_dist);
}

void	calc_draw_start_and_draw_end(t_data *data)
{
	int	draw_start;

	draw_start = (-1) * data->var.line_height / 2 + SCREEN_HEIGHT / 2;
	data->var.draw_start = draw_start;
	if (data->var.draw_start < 0)
		data->var.draw_start = 0;
	data->var.draw_end = data->var.line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->var.draw_end >= SCREEN_HEIGHT)
		data->var.draw_end = SCREEN_HEIGHT - 1;
}

void	calc_tex_x(t_data *data)
{
	if (data->var.side == 0)
		data->var.wall_x = data->var.pos_y + \
			data->var.perp_wall_dist * data->var.ray_y;
	else
		data->var.wall_x = data->var.pos_x + \
			data->var.perp_wall_dist * data->var.ray_x;
	data->var.wall_x -= floor(data->var.wall_x);
	data->var.tex_x = (int)(data->var.wall_x * (double)TEX_WIDTH);
	if (data->var.side == 0 && data->var.ray_x > 0)
		data->var.tex_x = TEX_WIDTH - data->var.tex_x - 1;
	if (data->var.side == 1 && data->var.ray_y < 0)
		data->var.tex_x = TEX_WIDTH - data->var.tex_x - 1;
}

void	draw_vertical_texture_stripe(int x, t_data *data)
{
	double	step;
	double	tex_pos;
	int		y;

	step = 1.0 * TEX_HEIGHT / data->var.line_height;
	tex_pos = (data->var.draw_start - SCREEN_HEIGHT / 2 \
		+ data->var.line_height / 2) * step;
	y = data->var.draw_start;
	while (y < data->var.draw_end)
	{
		data->var.tex_y = (int) tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		data->var.color = data->texture[data->var.tex_num][TEX_HEIGHT \
			* data->var.tex_y + data->var.tex_x];
		if (data->var.side == 1)
			data->var.color = (data->var.color >> 1) & 8355711;
		my_mlx_pixel_put(data, x, y, data->var.color);
		y++;
	}
}

void	raycast_loop(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		calc_ray_pos_and_dir(x, data);
		set_box_pos(data);
		calc_delta_dist(data);
		calc_step_and_side_dist(data);
		dda(data);
		calc_dist_perp(data);
		calc_vertical_line_height(data);
		calc_draw_start_and_draw_end(data);
		calc_tex_x(data);
		draw_vertical_texture_stripe(x, data);
		x++;
	}
	printf("%s\n", data->xpm[0]);
}
