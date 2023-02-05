/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_malloc_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:48:09 by broy              #+#    #+#             */
/*   Updated: 2023/01/17 14:04:51 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_len_env_var(char *var, char **env)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
		{
			j = 0;
			size = 0;
			while (env[i][j] != '=')
				j++;
			j++;
			while (env[i][j++])
				size++;
			return (size);
		}
		i++;
	}
	return (0);
}

static int	ft_strlen_free(char *str, int i, char *itoa)
{
	int	ret;
	int	j;

	j = 0;
	ret = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
		ret++;
	}
	while (itoa[j])
	{
		j++;
		ret++;
	}
	free(itoa);
	return (ret);
}

static int	ft_size_var(char *str, int i, char **env)
{
	char	*var;
	int		j;
	int		size;

	size = 0;
	j = i;
	while (str[j] && str[j] != ' ' && str[j] != '"' && str[j++] != '$')
		size++;
	var = ft_calloc(size + 1, 1);
	if (!var)
		return (0);
	j = 0;
	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '$')
	{
		var[j] = str[i];
		j++;
		i++;
	}
	j = 0;
	if (str[i] != 0)
		j = 1;
	j += get_len_env_var(var, env);
	free(var);
	return (j);
}

static int	ft_size_malloc_2(char *str, int *i, int *var_env, char **env)
{
	int	size;

	size = 0;
	if (str[*i] == '\'')
	{	
		size++;
		while (str[++(*i)] != '\'')
			size++;
	}
	if (str[*i] == '$' && str[*i + 1] != '$' && str[*i + 1]
		!= ' ' && str[*i + 1] != 0 && str[*i + 1] != '"')
	{
		if (str[*i + 1] == '?')
			size += ft_strlen_free(str, *i, ft_itoa(g_exit_status));
		else
			size += ft_size_var(str, *i + 1, env);
		*var_env = 0;
		(*i)++;
		while (str[*i] && str[*i] != ' ' && str[*i] != '$')
			(*i)++;
	}
	return (size);
}

int	ft_size_malloc(char *str, char **env)
{
	int	i;
	int	size;
	int	var_env;

	i = 0;
	size = 0;
	while (str[i])
	{
		var_env = 1;
		size += ft_size_malloc_2(str, &i, &var_env, env);
		size++;
		if (str[i] != 0 && str[i] != '$')
			i++;
	}
	if (var_env == 1)
		size++;
	return (size);
}
