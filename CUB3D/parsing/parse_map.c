/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:06:44 by broy              #+#    #+#             */
/*   Updated: 2023/03/03 15:06:48 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_check_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	return (1);
}

const char	*get_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ext == file)
		return ("");
	return (ext + 1);
}

int	ft_get_height(char *file)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		free(line);
		line = NULL;
	}
	return (i);
}

int	parse_map(char *file, int fd, t_data *data)
{
	char	*line;
	int		i;

	i = ft_get_height(file);
	if (i < 2)
		return (1);
	data->map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map[i] = ft_strdup(line);
		i++;
		free(line);
		line = NULL;
	}
	data->map[i] = NULL;
	ft_check_map(data->map);
	return (0);
}

static void	ft_quit(char *s, int fd)
{
	if (fd > 0)
		close(fd);
	write(2, s, ft_strlen(s));
	exit(1);
}

void	ft_parse(char *file, t_data *data)
{
	int	fd;

	if (ft_strncmp(get_ext(file), "cub", 4) != 0)
		ft_quit("Error\nInvalid extension\n", -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_quit("Error\nCannot open the map\n", fd);
	if (ft_parse_info(fd, data) == 1)
		ft_quit("Error\nInvalid information\n", fd);
	if (parse_map(file, fd, data) == 1)
		ft_quit("Error\nInvalid map\n", fd);
	close(fd);
	ft_launch(data);
}
