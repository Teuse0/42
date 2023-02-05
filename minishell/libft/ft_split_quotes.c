/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:18:25 by broy              #+#    #+#             */
/*   Updated: 2023/02/03 15:17:25 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		if (s[i] == '"' || s[i] == '\'')
		{
			i++;
			while (s[i] != '"' && s[i] != '\'')
				i++;
		}
		if (s[i] != c && j == 0)
		{
			j = 1;
			ret++;
		}
		else if (s[i] == c)
			j = 0;
		i += s[i] != 0;
	}
	return (ret);
}

static int	ft_size(const char *s, const char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			size++;
			i++;
			while (s[i] != '"' && s[i] != '\'')
			{
				size++;
				i++;
			}
		}
		if (s[i])
		{
			size++;
			i++;
		}
	}
	return (size);
}

static char	*ft_makeword(const char *s, char c)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc(ft_size(s, c) + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			str[i] = s[i];
			i++;
			while (s[i] && s[i] != '"' && s[i] != '\'')
			{
				str[i] = s[i];
				i++;
			}
		}
		str[i] = s[i];
		if (s[i])
			i++;
	}
	return (str);
}

void	ft_split_quotes_loop(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			str[j++] = ft_makeword(s + i, c);
			while (s[i] && s[i] != c)
			{
				if (s[i] == '"' || s[i] == '\'')
				{
					i++;
					while (s[i] != '"' && s[i] != '\'')
						i++;
				}
				i++;
			}
		}
	}
}

char	**ft_split_quotes(char const *s, char c)
{
	char		**str;

	if (!s)
		return (NULL);
	str = ft_calloc(ft_countwords(s, c) + 1, sizeof(*str));
	if (!str)
		return (NULL);
	ft_split_quotes_loop(s, c, str);
	return (str);
}
