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

static int	is_closed(int i, int j, t_data *data)
{
	if (data->map[i][j] == '0' \
		|| (data->map[i][j] != '1' && data->map[i][j] != ' '))
	{
		if (i == 0 || !data->map[i + 1] || j == 0 || !data->map[i][j + 1])
			return (1);
		if (data->map[i - 1] && data->map[i - 1][j]
			&& data->map[i - 1][j] == ' ')
			return (2);
		if (data->map[i + 1] && data->map[i + 1][j]
			&& data->map[i + 1][j] == ' ')
			return (3);
		if (data->map[i] && data->map[i][j - 1]
			&& data->map[i][j - 1] == ' ')
			return (4);
		if (data->map[i] && data->map[i][j + 1]
			&& data->map[i][j + 1] == ' ')
			return (5);
	}
	return (0);
}

/*static int	is_end(int index, t_data *data)
{
	int		i;

	i = index;
	i++;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > 0)
			return (1);
		i++;
	}
	data->map[i] = NULL;
	return (0);
}*/

int	check_map(t_data *data)
{
	int	i;
	int	j;


	if (ft_arrlen(data->map) < 3 || check_chars(data) != 1)
		return (1);
	i = 0;
	while (data->map[i])
	{
		/*if (ft_strlen(data->map[i]) == 0)
		{
			if (is_end(i) == 1)
				return (1);
			break ;
		}*/
		j = 0;
		while (data->map[i][j])
		{
			if (is_closed(i, j, data) && data->map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_init(t_data *data)
{
	void	*tmp;

	data->mlx = mlx_init();
	if (init_textures(data))
	{
		write(2, "Wrong texture\n", 14);
		exit(0);
		//ft_exit(data);
	}
	if (init_colors(data))
	{
		write(2, "Wrong rgb\n", 10);
		ft_exit(data);
	}
	if (check_map(data))
	{
		write(2, "Wrong map\n", 10);
		ft_exit(data);
	}
	tmp = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "><> |CUB3D| <><");
	data->win = tmp;
}
