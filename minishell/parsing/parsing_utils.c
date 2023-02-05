/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:25 by broy              #+#    #+#             */
/*   Updated: 2023/01/17 14:01:53 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_double_sep(char *str, int i)
{
	char	*ret;

	ret = malloc(sizeof(*ret) * 3);
	if (!ret)
		return (NULL);
	if (str[i] == '>' && str[i + 1] == '>')
	{
		ret[0] = '>';
		ret[1] = '>';
	}
	else if (str[i] == '<' && str[i + 1] == '<')
	{
		ret[0] = '<';
		ret[1] = '<';
	}
	ret[2] = 0;
	return (ret);
}

char	*ft_simple_sep(char *str, int i)
{
	char	*ret;

	ret = malloc(sizeof(*ret) * 2);
	if (!ret)
		return (NULL);
	if (str[i] == '|')
		ret[0] = '|';
	else if (str[i] == '>')
		ret[0] = '>';
	else if (str[i] == '<')
		ret[0] = '<';
	ret[1] = 0;
	return (ret);
}

void	ft_free_lst_cmd(char **lst_cmd)
{
	int	i;

	i = 0;
	while (lst_cmd[i])
	{
		free(lst_cmd[i]);
		i++;
	}
	free(lst_cmd);
}

char	*ft_sep(char *str, int i)
{
	char	*ret;

	ret = NULL;
	if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<'
			&& str[i + 1] == '<'))
	{
		ret = ft_double_sep(str, i);
		if (!ret)
			return (NULL);
	}
	else if (str[i] == '|' || (str[i] == '<') || (str[i] == '>'))
	{
		ret = ft_simple_sep(str, i);
		if (!ret)
			return (NULL);
	}
	return (ret);
}

int	ft_size_str(char *str, int i)
{
	char	quote;

	while (str[i] == ' ')
		i++;
	if (str[i] == '|' || str[i] == '>' || str[i] == '<')
		return (0);
	while (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			while (str[i] != quote && str[i])
				i++;
		}
		if (str[i] != 0)
			i++;
	}
	return (i);
}
