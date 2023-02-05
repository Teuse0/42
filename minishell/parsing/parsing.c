/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:48:40 by broy              #+#    #+#             */
/*   Updated: 2023/02/03 15:52:52 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_copy_str(char *lst_cmd, char *str, int i)
{
	int		k;
	char	quote;

	k = 0;
	while (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			lst_cmd[k++] = str[i++];
			while (str[i] != quote)
			{
				lst_cmd[k] = str[i];
				i++;
				k++;
			}
		}
		lst_cmd[k] = str[i];
		i++;
		k++;
	}
	if (lst_cmd)
		lst_cmd[k] = 0;
	return (i);
}

static int	ft_add_sep(char **lst_cmd, char *str, int i, int *j)
{
	if (lst_cmd[*j])
		(*j)++;
	lst_cmd[*j] = ft_sep(str, i);
	if (lst_cmd[*j] == NULL)
	{
		ft_free_lst_cmd(lst_cmd);
		return (0);
	}
	return (1);
}

static char	***ft_trim_all(char **lst_cmd, int j, char **env)
{
	int				i;
	char			**str;

	str = ft_calloc(j + 1, sizeof(*str));
	if (!str)
	{
		ft_free_lst_cmd(lst_cmd);
		return (NULL);
	}
	i = 0;
	while (lst_cmd[i])
	{
		str[i] = ft_strtrim(lst_cmd[i], " ");
		if (!str[i])
		{
			ft_free_lst_cmd(lst_cmd);
			return (NULL);
		}
		str[i] = ft_remove_spaces(str[i]);
		free(lst_cmd[i++]);
	}
	return (sep_and_reorder(lst_cmd, str, env));
}

static int	ft_pars_loop(char **lst_cmd, char *str, int *i, int *j)
{
	int	size;

	while (str[(*i)])
	{
		size = ft_size_str(str, (*i));
		if (size != 0)
		{
			lst_cmd[(*j)] = ft_calloc(size + 1, 1);
			if (!lst_cmd[(*j)])
			{
				ft_free_lst_cmd(lst_cmd);
				return (0);
			}
			(*i) = ft_copy_str(lst_cmd[(*j)], str, (*i));
		}
		while (str[(*i)] == ' ')
			(*i)++;
		if (str[(*i)] && !ft_add_sep(lst_cmd, str, (*i), j))
			return (0);
		if (str[(*i)])
			(*i) += ft_strlen(lst_cmd[(*j)]) == 2;
		(*j)++;
		(*i) += str[(*i)] != 0;
	}
	return (1);
}

char	***ft_pars(char *str, char **env)
{
	int		i;
	int		j;
	char	**lst_cmd;

	lst_cmd = ft_calloc(ft_size_tab(str) + 1, sizeof(*lst_cmd));
	if (!lst_cmd)
		return (NULL);
	j = 0;
	i = 0;
	if (!ft_pars_loop(lst_cmd, str, &i, &j))
		return (NULL);
	return (ft_trim_all(lst_cmd, j, env));
}
