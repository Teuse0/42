/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:08:45 by broy              #+#    #+#             */
/*   Updated: 2023/01/31 16:08:46 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_var_env(char *var, char **env)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
		{
			j = 0;
			k = 0;
			tmp = ft_calloc(get_len_env_var(var, env) + 1, sizeof(*tmp));
			while (env[i][j] != '=')
				j++;
			j++;
			while (env[i][j])
				tmp[k++] = env[i][j++];
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

char	*ft_get_var(char *str, int i, char **env)
{
	char	*tmp;
	char	*ret;
	int		j;

	j = 0;
	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '\''
		&& str[i] != '$')
	{
		j++;
		i++;
	}
	tmp = ft_calloc(j + 1, sizeof(*tmp));
	if (!tmp)
		return (NULL);
	j--;
	while (j >= 0)
		tmp[j--] = str[--i];
	ret = ft_get_var_env(tmp, env);
	if (!ret)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (ret);
}
