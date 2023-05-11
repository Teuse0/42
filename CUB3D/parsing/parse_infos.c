/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:45:52 by broy              #+#    #+#             */
/*   Updated: 2023/03/03 15:45:53 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

static int	textures(char *line, t_data *data)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!tmp)
		return (1);
	if (ft_arrlen(tmp) != 2)
		return (1);
	if (ft_strncmp(tmp[0], "NO", 3) == 0)
		data->xpm[0] = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "EA", 3) == 0)
		data->xpm[1] = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "SO", 3) == 0)
		data->xpm[2] = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "WE", 3) == 0)
		data->xpm[3] = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "C", 2) \
		&& ft_strncmp(tmp[0], "F", 2))
		return (1);
	ft_free(tmp);
	return (0);
}

static int	rgb(char *line, t_data *data)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!tmp)
		return (1);
	if (ft_arrlen(tmp) != 2)
		return (1);
	if (ft_strncmp(tmp[0], "F", 1) == 0)
		data->rgb[0] = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "C", 1) == 0)
		data->rgb[1] = ft_strdup(tmp[1]);
	ft_free(tmp);
	return (0);
}

int	ft_parse_info(int fd, t_data *data)
{
	char	*line;

	data->xpm = ft_calloc(sizeof(char *), 5);
	if (!data->xpm)
		return (1);
	data->rgb = ft_calloc(sizeof(char *), 3);
	if (!data->rgb)
		return (1);
	while (ft_arrlen(data->xpm) != 4 || ft_arrlen(data->rgb) != 2)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) == 0 || line[0] == '\n')
			;
		else if (textures(line, data) == 1 || rgb(line, data) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
		if (line == NULL)
			break ;
	}
	return (0);
}
