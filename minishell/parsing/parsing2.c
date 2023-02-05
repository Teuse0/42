/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:48:40 by broy              #+#    #+#             */
/*   Updated: 2023/02/03 15:21:09 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	double_increment(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

static int	ft_size_ret(char *str)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			double_increment(&i, &size);
			while (str[i] && str[i] != '"' && str[i] != '\'')
				double_increment(&i, &size);
		}
		if (str[i] == ' ')
		{
			double_increment(&i, &size);
			while (str[i] == ' ' && str[i])
				i++;
		}
		else if (str[i++] != 0)
			size++;
	}
	return (size);
}

static void	ft_remove_spaces_loop(char *str, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			ret[j++] = str[i++];
			while (str[i] && str[i] != '"' && str[i] != '\'')
				ret[j++] = str[i++];
		}
		if (str[i] == ' ')
		{
			ret[j++] = str[i++];
			while (str[i] == ' ' && str[i])
				i++;
		}
		else if (str[i] != 0)
			ret[j++] = str[i++];
	}
}

char	*ft_remove_spaces(char *str)
{
	char	*ret;

	ret = ft_calloc(ft_size_ret(str) + 1, 1);
	if (!ret)
		return (NULL);
	ft_remove_spaces_loop(str, ret);
	free(str);
	return (ret);
}

char	***sep_and_reorder(char **lst_cmd, char **str, char **env)
{
	char	***raw_cmds;

	free(lst_cmd);
	ft_pars_env(str, env);
	order_redir(&str);
	order_heredeocs(&str);
	raw_cmds = sep_cmds(str);
	ft_split_free(str);
	if (!raw_cmds)
		return (NULL);
	return (raw_cmds);
}
