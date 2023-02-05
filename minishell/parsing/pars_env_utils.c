/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:44:28 by broy              #+#    #+#             */
/*   Updated: 2023/01/17 14:01:43 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_dollar(char *str, int i)
{
	if (str[0] == '$' && str[1] != '$')
		return (1);
	return (str[i] == '$' && str[i + 1] != '$' && str[i - 1] != '$'
		&& str[i + 1] != ' ' && str[i + 1] != 0 && str[i + 1] != '"');
}

int	ft_single_quote_env(char *str, char *ret, int *i, int size)
{
	if ((str[*i] == '\'' && *i == 0) || (str[*i] == '\'' && i != 0
			&& str[*i - 1] != '"' && str[*i - 1] != '\'' && str[*i + 1]))
	{
		(*i)++;
		ret[size++] = str[(*i)++];
		while (str[*i] != '\'')
			ret[size++] = str[(*i)++];
		return (-1);
	}
	return (size);
}

int	ft_copy_tmp(char *ret, char *tmp, int size)
{
	int	j;

	j = 0;
	if (tmp == NULL)
		return (size);
	while (tmp[j])
		ret[size++] = tmp[j++];
	return (size);
}

int	ft_check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != 0
			&& str[i + 1] != '$' && str[i + 1] != '"')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	join = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(*join));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	free(s2);
	return (join);
}
