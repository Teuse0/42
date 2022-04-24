/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:56:38 by vnaud             #+#    #+#             */
/*   Updated: 2022/03/06 14:29:24 by rgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*ft_strdup(char *src)
{
	char			*str_res;
	unsigned int	index;

	index = 0;
	str_res = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (str_res == NULL)
	{
		errno = ENOMEM;
		return (str_res);
	}
	while (src[index])
	{
		str_res[index] = src[index];
		index++;
	}
	str_res[index] = '\0';
	return (str_res);
}

char	*ft_ten_power(int nbr)
{
	char	*res;

	res = malloc(sizeof(char) * (nbr + 2));
	res[nbr + 1] = '\0';
	while (nbr != 0)
	{
		res[nbr] = '0';
		nbr--;
	}
	res[nbr] = '1';
	return (res);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = src[index];
	return (dest);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s1[index] == s2[index])
	{
		index++;
	}
	return (s1[index] - s2[index]);
}
