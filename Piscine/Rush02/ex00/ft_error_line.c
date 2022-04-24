/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_error_line.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: luserbu <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2022/03/06 12:45:26 by luserbu	       #+#    #+#	      */
/*   Updated: 2022/03/06 18:06:03 by vnaud            ###   ########.fr       */
/*									      */
/* ************************************************************************** */
#include "ft_rush02.h"

int	error_double_point(char *str, int index)
{
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == ':')
	{
		if (str[index] < 32 && str[index] == 127)
			return (0);
		else if (str[index] == ' '
			|| (str[index] >= 9 && str[index] <= 13))
		{
			while (str[index] == ' '
				|| (str[index] >= 9 && str[index] <= 13))
			{
				if (str[index + 1] != ' '
					|| str[index + 1] != ':'
					|| (!(str[index + 1] >= 9
							&& str[index + 1] <= 13)))
					return (0);
				index++;
			}
		}
		else
			index++;
	}
	return (index + 1);
}

int	error_back_slash(char *str, int index)
{
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] != '\n')
	{
		if (str[index] < 32 && str[index] == 127)
			return (0);
		else if (str[index] == ' '
			|| (str[index] >= 9 && str[index] <= 13))
		{
			while (str[index] == ' '
				|| (str[index] >= 9 && str[index] <= 13))
			{
				if (str[index + 1] != ' '
					|| str[index + 1] != ':'
					|| (!(str[index + 1] >= 9
							&& str[index + 1] <= 13)))
					return (0);
				index++;
			}
		}
		else
			index++;
	}
	return (1);
}

int	double_point(char *str)
{
	int	index;

	index = 0;
	while (str[index] != ':')
	{
		if (str[index] == '\n')
			return (0);
		index++;
	}
	while (str[index] != '\n')
	{
		index++;
		if (str[index] == ':')
			return (0);
	}
	return (1);
}

int	error_line(char *str)
{
	int	index;
	int	good_line;

	index = 0;
	good_line = 0;
	if ((str[index] < '0' && str[index] > '9') || str[index] != ' '
		|| (!(str[index] >= 9 && str[index] <= 13)))
		return (0);
	if (double_point(str) == 1)
		good_line++;
	else
		return (0);
	index = error_double_point(str, index);
	if (index == 0)
		return (0);
	if (error_back_slash(str, index) == 0)
		return (0);
	return (1);
}
