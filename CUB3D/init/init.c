/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:10:42 by broy              #+#    #+#             */
/*   Updated: 2023/03/05 19:10:44 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init(t_data *data)
{
	void	*tmp;

	if (init_colors(data))
	{
		write(2, "Wrong rgb\n", 10);
		ft_exit(data);
	}
	data->mlx = mlx_init();
	tmp = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "><> |CUB3D| <><");
	data->win = tmp;
}
