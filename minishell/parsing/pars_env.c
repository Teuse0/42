/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:58:35 by broy              #+#    #+#             */
/*   Updated: 2023/02/02 05:34:32 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_get_value(char *str, int i)
{
	char	*tmp;
	char	*ret;
	int		j;

	j = 0;
	tmp = ft_itoa(g_exit_status);
	if (str[i + 1] == 0 || str[i + 1] == ' ')
		return (tmp);
	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '$')
	{
		j++;
		i++;
	}
	ret = ft_calloc(j, sizeof(*ret));
	if (!ret)
		return (NULL);
	i = i - j + 1;
	j = 0;
	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '$')
		ret[j++] = str[i++];
	ret = ft_strjoin_free(tmp, ret);
	free(tmp);
	return (ret);
}

static char	*ft_get(char *str, int i, char **env)
{
	char	*tmp;

	if (str[i] == '?')
		tmp = ft_get_value(str, i);
	else
		tmp = ft_get_var(str, i, env);
	return (tmp);
}

static void	ft_get_env_2(char *str, int i, char **env, char *ret)
{
	int		size;
	char	*tmp;

	size = 0;
	while (str[i])
	{
		size = ft_single_quote_env(str, ret, &i, size);
		if (size == -1)
			return ;
		if (is_dollar(str, i))
		{
			tmp = ft_get(str, i + 1, env);
			size = ft_copy_tmp(ret, tmp, size);
			i++;
			while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '$')
				i++;
			free(tmp);
		}
		else if (str[i] != 0 && str[i] != '\'' && str[i] != '"')
			ret[size++] = str[i++];
		if (str[i] == '"')
			i++;
	}
}

static char	*ft_get_env(char *str, int i, char **env)
{
	char	*ret;

	ret = ft_calloc(ft_size_malloc(str, env), sizeof(*ret));
	if (!ret)
		return (NULL);
	ft_get_env_2(str, i, env, ret);
	free(str);
	return (ret);
}

void	ft_pars_env(char **lst_cmd, char **env)
{
	int	i;
	int	check;

	i = 0;
	while (lst_cmd[i])
	{
		check = ft_check_dollar(lst_cmd[i]);
		if (check)
		{
			check = 0;
			lst_cmd[i] = ft_get_env(lst_cmd[i], check, env);
			if (!lst_cmd[i])
				return ;
		}
		i++;
	}
}
