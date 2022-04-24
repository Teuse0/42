/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:56:44 by broy              #+#    #+#             */
/*   Updated: 2022/04/06 15:56:47 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0)
		{
			j = 1;
			ret++;
		}
		else if (s[i] == c)
			j = 0;
		i++;
	}
	return (ret);
}

static char	*ft_makeword(const char *s, int start, int end)
{
	char	*str;
	int		i;

	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		j;
	int			k;

	str = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (/*!s || */!str)
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	while (s[i] || i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			str[j] = ft_makeword(s, k, i);
			j++;
			k = -1;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
