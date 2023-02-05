/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:45:50 by tguerin           #+#    #+#             */
/*   Updated: 2023/01/31 20:14:50 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	find_var_index(char **env, char *s)
{
	char	**tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		tmp = ft_split(env[i], '=');
		if (!tmp)
			return (-1);
		if (ft_strncmp(tmp[0], s, ft_strlen(s) + 1) == 0)
		{
			ft_split_free(tmp);
			return (i);
		}
		ft_split_free(tmp);
		i++;
	}
	return (-1);
}

static void	move_without_index(char **env, char **new_env, int index)
{
	int		exceed;
	int		i;

	exceed = 0;
	i = 0;
	while (env[i])
	{
		if (i != index)
			new_env[i - exceed] = env[i];
		else
		{
			free(env[i]);
			exceed = 1;
		}
		i++;
	}
	new_env[i - exceed] = NULL;
}

static int	remove_from_env(char ***env, char *s)
{
	char	**new_env;
	int		s_index;

	s_index = find_var_index(*env, s);
	if (s_index == -1)
		return (1);
	new_env = malloc(sizeof(*new_env) * ft_split_size(*env));
	if (!new_env)
		return (0);
	move_without_index(*env, new_env, s_index);
	free(*env);
	*env = new_env;
	return (1);
}

int	unset(int argc, char **argv, char ***env)
{
	int	return_value;
	int	i;

	return_value = EXIT_SUCCESS;
	i = 1;
	while (i < argc)
	{
		if (!ft_isalpha(argv[i][0]) && argv[i][0] != '_')
		{
			ft_fprintf(2, "minishell: unset: `%s': not a valid identifier\n",
				argv[i]);
			return_value = EXIT_FAILURE;
			i++;
			continue ;
		}
		if (!remove_from_env(env, argv[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (return_value);
}
