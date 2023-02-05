/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:43:13 by tguerin           #+#    #+#             */
/*   Updated: 2023/01/31 20:12:33 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_valid_env_var(char *env_var)
{
	int		i;

	if (!ft_isalpha(env_var[0]) && env_var[0] != '_')
		return (0);
	i = 1;
	while (env_var[i] && env_var[i] != '=')
	{
		if ((!ft_isalnum(env_var[i]) && env_var[i] != '_' && env_var[i] != '+')
			|| (env_var[i] == '+' && env_var[i + 1] != '='))
			return (0);
		i++;
	}
	return (1);
}

static void	print_begin(char *env_var, int lim)
{
	ft_fprintf(1, "declare -x ");
	write(1, env_var, lim);
}

static int	show_env(char **env)
{
	char	**tmp;
	char	*equal;
	int		lim;
	int		i;

	tmp = ft_split_dup(env);
	if (!tmp)
		return (0);
	ft_split_sort(tmp, 1);
	i = 0;
	while (tmp[i])
	{
		equal = ft_strchr(tmp[i], '=');
		if (equal)
		{
			lim = equal - tmp[i];
			print_begin(tmp[i], lim);
			ft_fprintf(1, "=\"%s\"\n", tmp[i] + lim + 1);
		}
		else
			ft_fprintf(1, "declare -x %s\n", tmp[i]);
		i++;
	}
	ft_split_free(tmp);
	return (1);
}

int	export(int argc, char **argv, char ***env)
{
	int	return_value;
	int	i;

	if (argc == 1)
		return (!show_env(*env));
	return_value = EXIT_SUCCESS;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_env_var(argv[i]))
		{
			ft_fprintf(2, "minishell: export: `%s': not a valid identifier\n",
				argv[i]);
			return_value = EXIT_FAILURE;
			i++;
			continue ;
		}
		if (!ft_putenv(env, argv[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (return_value);
}
