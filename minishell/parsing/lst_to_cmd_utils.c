/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:23 by broy              #+#    #+#             */
/*   Updated: 2023/02/01 17:53:49 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_free(char *s1, char const *set)
{
	char	*trim;
	int		begin;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	begin = 0;
	while (is_in(s1[begin], set))
		begin++;
	end = ft_strlen(s1) - 1;
	while (is_in(s1[end], set))
		end--;
	end++;
	trim = ft_calloc(sizeof(char) * ((end - begin) * (end - begin > 0) + 1), 1);
	if (!trim)
		return (NULL);
	i = 0;
	while (begin + i < end)
	{
		trim[i] = s1[begin + i];
		i++;
	}
	free(s1);
	return (trim);
}

int	ft_is_cmd(char *arg, char **env, int *error_flag)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if (!arg)
		return (1);
	if (!ft_strncmp(arg, "cd", 2) || !ft_strncmp(arg, "exit", 4)
		|| !ft_strncmp(arg, "export", 6) || !ft_strncmp(arg, "unset", 5))
		return (1);
	tmp = cmd_path(env, arg, error_flag);
	if (tmp)
	{
		ret = 1;
		free(tmp);
	}
	return (ret);
}

int	ft_size_arg(char *str, int i)
{
	int	size;

	size = 0;
	while (str[i] != ' ' && str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			i++;
			size++;
			while (str[i] && str[i] != '"' && str[i] != '\'')
			{
				i++;
				size++;
			}
		}
		size++;
		i++;
	}
	return (size);
}

int	ft_nbr_args(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
			i++;
		size++;
		if (str[i] != 0)
			i++;
	}
	return (size + 1);
}
