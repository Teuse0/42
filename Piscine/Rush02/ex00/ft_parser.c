/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 10:03:42 by vnaud             #+#    #+#             */
/*   Updated: 2022/03/06 18:45:58 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

//	Count the number of line if file at "path".
int	ft_count_line(char *path)
{
	int		file;
	char	c;
	int		size;
	int		line;

	file = open(path, O_RDONLY);
	if (file < 0)
		return (-1);
	size = 0;
	line = 0;
	while (read(file, &c, 1) != 0)
	{
		if (c != '\n')
		{
			size++;
		}
		else
		{
			if (size != 0)
				line++;
			size = 0;
		}
	}
	close(file);
	return (line);
}

// Check integrity of data buffer
t_dict	*ft_upload_dict(t_dict *dict, char *buffer)
{
	int		index;
	char	**res;

	index = 0;
	res = ft_split(buffer, "\n");
	while (res[index] != 0)
	{
		if (!error_line(res[index]))
		{
			ft_upload_data(res, dict, index);
		}
		else
		{
			return (NULL);
		}
		index++;
	}
	return (dict);
}

//	Parse the file at "path" to return dict with {Key, Value}.
t_dict	*ft_parser(char *path)
{
	int		file;
	t_dict	*dict;
	char	buffer[8192];
	int		index;
	int		line;

	index = 0;
	line = ft_count_line(path);
	file = open(path, O_RDONLY);
	if (file < 0)
		return (NULL);
	dict = malloc(sizeof(t_dict) * (line + 1));
	dict[line] = *(ft_dict_entry("null:null"));
	while (read(file, &buffer[index], 1) > 0)
		index++;
	close(file);
	ft_upload_dict(dict, buffer);
	return (dict);
}
