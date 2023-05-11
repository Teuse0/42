/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:30:54 by broy              #+#    #+#             */
/*   Updated: 2023/04/29 22:30:55 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_texture_array(int i, t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->tex[i].height)
	{
		x = -1;
		while (++x < data->tex[i].width)
		{
			data->texture[i][data->tex[i].height * y + x] = \
				(data->tex[i].addr[data->tex[i].height * y + x]);
		}
	}
}

int	init_textures(t_data *data)
{
	int		i;
	void	*tmp;
	int		*addr;

	i = 0;
	while (i < 4)
	{
		tmp = mlx_xpm_file_to_image(data->mlx, "textures/NO.xpm", \
			&(data->tex[i].width), &(data->tex[i].height));
		data->tex[i].ptr_img = tmp;
		if (!data->tex[i].ptr_img)
		{
			printf("%s\n", data->xpm[i]);
			printf("%d\n", data->tex[i].height);
			return (1);
		}
		addr = (int *) mlx_get_data_addr(data->tex[i].ptr_img, \
			&data->tex[i].bits_per_pixel, &data->tex[i].line_len, \
			&data->tex[i].endian);
		data->tex[i].addr = addr;
		if (!data->tex[i].addr)
			return (1);
		fill_texture_array(i, data);
		mlx_destroy_image(data->mlx, data->tex[i].ptr_img);
		i++;
	}
	return (0);
}
