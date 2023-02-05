/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:56:19 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/02 21:41:16 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static void	remove_trailing_plus(char **tmp1)
{
	if (tmp1[0][ft_strlen(tmp1[0]) - 1] == '+')
		tmp1[0][ft_strlen(tmp1[0]) - 1] = '\0';
}

static int	is_begin_of(char *s1, char *s2)
{
	char	**split;
	int		return_value;

	split = ft_split(s1, '=');
	if (!split)
		return (0);
	if (!split[0])
	{
		ft_split_free(split);
		return (0);
	}
	return_value = ft_strncmp(split[0], s2, ft_strlen(s2) + 1) == 0;
	ft_split_free(split);
	return (return_value);
}

static int	modify_env(char **env_var, char **s_split, char *s)
{
	char	*to_free;
	char	*tmp;

	if (!s_split[1])
		return (1);
	to_free = *env_var;
	if (s[ft_strlen(s_split[0])] == '+')
	{
		if (ft_strchr(*env_var, '=') == NULL)
			tmp = ft_strjoin(*env_var, "=");
		else
			tmp = ft_strjoin(*env_var, "");
		*env_var = ft_strjoin(tmp, s_split[1]);
		free(tmp);
	}
	else
		*env_var = ft_strdup(s);
	if (!*env_var)
	{
		*env_var = to_free;
		return (0);
	}
	free(to_free);
	return (1);
}

static int	add_to_env(char ***env, char *s)
{
	char	**tmp1;
	char	*tmp2;
	int		is_success;
	int		i;

	tmp1 = ft_split(s, '=');
	if (!tmp1)
		return (0);
	remove_trailing_plus(tmp1);
	i = 0;
	while ((*env)[i])
	{
		if (is_begin_of((*env)[i], tmp1[0]))
		{
			is_success = modify_env(*env + i, tmp1, s);
			ft_split_free(tmp1);
			return (is_success);
		}
		i++;
	}
	ft_split_free(tmp1);
	tmp2 = ft_strnstr(s, "+=", ft_strlen(s));
	if (tmp2)
		ft_strrem(s, tmp2 - s);
	return (ft_split_append(env, s));
}

int	ft_putenv(char ***env, const char *s)
{
	char	*copy;
	int		is_success;

	copy = ft_strdup(s);
	if (!copy)
		return (0);
	is_success = add_to_env(env, copy);
	free(copy);
	return (is_success);
}
