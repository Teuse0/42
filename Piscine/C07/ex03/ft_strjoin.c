/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:35:03 by broy              #+#    #+#             */
/*   Updated: 2022/03/03 17:34:07 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_cstr(int size, char **strs, char *sep)
{
	char	*str;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (i < size)
	{
		l = l + ft_strlen(strs[i]);
		i++;
	}
	l = l + ft_strlen(sep) * (size - 1);
	str = (char *)malloc(sizeof(char) * l);
	return (str);
}

int	ft_sep(int k, char *str, char *sep)
{
	int	j;

	j = 0;
	while (sep[j])
	{
		str[k] = sep[j];
		j++;
		k++;
	}
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = ft_cstr(size, strs, sep);
	if (size == 0)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k] = strs[i][j];
			k++;
			j++;
		}
		if (i != (size - 1))
			str[k] = ft_sep(k, str, sep);
		i++;
	}
	str[k] = '\n';
	return (str);
}
