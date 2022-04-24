/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 08:23:38 by vnaud             #+#    #+#             */
/*   Updated: 2022/03/06 19:12:55 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

// Return the value from key to find thousand and more in dict
char	*ft_get_type(t_dict *dict, char *nbr)
{
	int		size;
	int		var;
	char	*key;
	char	*res;
	int		index;

	size = ft_strlen(nbr);
	index = 0;
	if (size % 3 == 0)
		var = size - 3;
	else
		var = size - (size % 3);
	key = ft_ten_power(var);
	while (ft_strcmp(dict[index].value_num, "null") != 0
		&& ft_strcmp(dict[index].value_num, key) != 0)
		index++;
	res = ft_strdup(dict[index].value_alpha);
	free(key);
	return (res);
}

// Return the value from key in dict
char	*ft_get_value(t_dict *dict, char *nbr)
{
	char	*res;
	int		index;

	index = 0;
	while (ft_strcmp(dict[index].value_num, "null") != 0
		&& ft_strcmp(dict[index].value_num, nbr) != 0)
	{
		index++;
	}
	res = ft_strdup(dict[index].value_alpha);
	return (res);
}

int	ft_pattern_three(t_dict *dict, char *nbr)
{
	char	*res;
	char	*print;

	res = malloc(sizeof(char) * 3);
	res[0] = nbr[0];
	res[1] = '\0';
	print = ft_get_value(dict, res);
	ft_putstr(print);
	write(1, " ", 1);
	print = ft_get_value(dict, "100");
	ft_putstr(print);
	res[0] = nbr[1];
	res[1] = nbr[2];
	res[2] = '\0';
	write(1, " ", 1);
	ft_pattern_two(dict, res);
	free(res);
	return (0);
}

int	ft_pattern_two(t_dict *dict, char *nbr)
{
	char	*res;
	char	*print;

	res = malloc(sizeof(char) * 3);
	res[0] = nbr[0];
	res[1] = '\0';
	if (ft_strcmp(res, "1") == 0)
	{
		print = ft_get_value(dict, nbr);
		ft_putstr(print);
	}
	else if (ft_strcmp(nbr, "00") != 0)
	{
		res[1] = '0';
		res[2] = '\0';
		print = ft_get_value(dict, res);
		ft_putstr(print);
		write(1, " ", 1);
		res[0] = nbr[1];
		res[1] = '\0';
		if (ft_strcmp(res, "0") != 0)
			ft_pattern_one(dict, res);
	}
	free(res);
	return (0);
}

int	ft_pattern_one(t_dict *dict, char *nbr)
{
	char	*print;

	print = ft_get_value(dict, nbr);
	ft_putstr(print);
	return (0);
}
