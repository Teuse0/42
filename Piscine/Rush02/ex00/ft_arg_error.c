/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:02:37 by luserbu           #+#    #+#             */
/*   Updated: 2022/03/06 16:19:55 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_arg_error(char *str)
{
	int	index;

	index = 0;
	if (str[0] == '\0')
		return (0);
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			index++;
		else
			return (0);
	}
	if (index >= 37)
		return (0);
	return (1);
}

int	ft_path_error(char *str)
{
	int	file;

	file = open(str, O_RDONLY);
	if (file == -1)
		return (0);
	close(file);
	return (1);
}
