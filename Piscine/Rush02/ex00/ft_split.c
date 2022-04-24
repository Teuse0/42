/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:50:05 by vnaud             #+#    #+#             */
/*   Updated: 2022/03/05 19:47:43 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

void	ft_count_word(char *str, char *charset, int *word_count)
{
	int	size;

	size = 0;
	while (*(str))
	{
		if (ft_is_in_charset(*str, charset))
		{
			if (size > 0)
			{
				*word_count += 1;
				size = 0;
			}
		}
		else
			size++;
		str++;
	}
	if (size > 0)
		*word_count += 1;
}

void	ft_add_word(char **res, char *str, int *size, int index)
{
	int	intern_index;

	intern_index = *size;
	res[++index] = malloc(sizeof(char) * *size + 1);
	res[index][*size] = '\0';
	while (*size > 0)
	{
		res[index][intern_index - *size] = *(str - *size);
		*size = *size - 1;
	}
}

void	ft_get_word(char **res, char *str, char *charset, int word_count)
{
	int	index;
	int	size;

	size = 0;
	index = -1;
	while (*str && index < word_count)
	{
		if (ft_is_in_charset(*str, charset))
		{
			if (size > 0)
				ft_add_word(res, str, &size, index++);
		}
		else
			size++;
		str++;
	}
	if (size > 0)
		ft_add_word(res, str, &size, index++);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		word_count;
	int		size;

	word_count = 0;
	if (*charset == '\0')
	{
		size = 0;
		res = malloc(sizeof(char *) * 2);
		while (str[size])
			size++;
		res[0] = malloc(sizeof(char) * (size + 1));
		res[0][size] = '\0';
		while (--size >= 0)
			res[0][size] = str[size];
		res[1] = 0;
		return (res);
	}
	ft_count_word(str, charset, &word_count);
	res = malloc(sizeof(char *) * (word_count + 1));
	ft_get_word(res, str, charset, word_count);
	res[word_count] = 0;
	return (res);
}
