/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:14:29 by broy              #+#    #+#             */
/*   Updated: 2023/03/05 19:14:31 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long	color_to_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static int	*validate_rgb(char **arr)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
		return (NULL);
	while (arr[i])
	{
		rgb[i] = ft_atoi(arr[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (NULL);
		i++;
	}
	rgb[i] = 0;
	return (rgb);
}

void	convert_colors(int *rgb, int i, t_data *data)
{
	if (i == 0)
		data->floor = color_to_hex(rgb[0], rgb[1], rgb[2]);
	if (i == 1)
		data->ceilling = color_to_hex(rgb[0], rgb[1], rgb[2]);
}

int	init_colors(t_data *data)
{
	int		i;
	char	**tmp;
	int		*rgb;

	i = 0;
	while (data->rgb[i])
	{
		tmp = ft_split(data->rgb[i], ',');
		if (!tmp)
			return (1);
		rgb = validate_rgb(tmp);
		if (!rgb)
		{
			free(rgb);
			return (1);
		}
		convert_colors(rgb, i, data);
		ft_free(tmp);
		free(rgb);
		i++;
	}
	return (0);
}
