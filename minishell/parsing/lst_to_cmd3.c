/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:55:51 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 19:55:58 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_change(char *str)
{
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != ' ' && str[i++])
		size++;
	tmp = ft_calloc(size + 1, 1);
	if (!tmp)
		return (NULL);
	i = 0;
	size = 0;
	while (str[i] != ' ' && str[i])
		tmp[size++] = str[i++];
	free(str);
	return (tmp);
}

void	ft_free_split(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

char	*ft_strjoin_free2(char *s1, char *s2)
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
	free(s1);
	return (join);
}

int	is_cmd(char **tmp, char **env, int j, int *error_flag)
{
	return (is_builtin(tmp[j]) || (ft_is_cmd(tmp[j], env, error_flag)
			&& (j != 0 && ft_strncmp(tmp[j - 1], "<", 1))));
}

int	ft_size_cmds(char **arg, int *error_flag, char **env)
{
	int		i;
	int		j;
	int		size;
	char	**tmp;

	size = 0;
	i = -1;
	while (arg[++i])
	{
		tmp = ft_split_quotes(arg[i], ' ');
		j = 0;
		while (tmp[j])
		{
			if (is_cmd(tmp, env, j, error_flag))
			{
				double_increment(&size, &j);
				while (tmp[j])
					double_increment(&size, &j);
			}
			else
				double_increment(&size, &j);
		}
		ft_free_split(tmp);
	}
	return (size);
}
