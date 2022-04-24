/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:33:55 by vnaud             #+#    #+#             */
/*   Updated: 2022/03/06 18:45:20 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

//	Create a new entry to add in dict.
t_dict	*ft_dict_entry(char *line)
{
	t_dict	*entry;
	char	**values;
	int		index;

	index = 0;
	values = ft_split(line, ":");
	entry = malloc(sizeof(t_dict));
	entry->value_num = ft_strdup(values[0]);
	entry->value_alpha = ft_strdup(values[1]);
	while (values[index] != 0)
	{
		free(values[index]);
		index++;
	}
	free(values);
	return (entry);
}

// Parse data into dict
t_dict	*ft_upload_data(char **res, t_dict *dict, int index)
{
	t_dict	*entry;
	int		size;
	char	buffer[4096];

	size = -1;
	while (*res[index] == ' ' || (*res[index] >= 9 && *res[index] <= 13))
		res[index]++;
	while (*res[index] >= '0' && *res[index] <= '9')
		buffer[++size] = *res[index]++;
	while (*res[index] == ' ' || *res[index] == ':')
		res[index]++;
	buffer[++size] = ':';
	while (*res[index] >= 32 && *res[index] <= 126)
		buffer[++size] = *res[index]++;
	buffer[++size] = '\0';
	entry = ft_dict_entry(buffer);
	dict[index] = *entry;
	return (dict);
}
