/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:42:23 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/01 02:54:37 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	add_to_env(char ***env, const char	*name, char *path)
{
	int		success;
	char	*env_var;

	env_var = ft_strjoin(name, path);
	if (!env_var)
		return (0);
	success = ft_putenv(env, env_var);
	free(env_var);
	return (success);
}

int	cd(int argc, char **argv, char ***env)
{
	char	actual_path[4097];

	if (argc == 1 || argc > 2)
	{
		ft_fprintf(2, "cd: too many arguments\n");
		return (EXIT_FAILURE);
	}
	getcwd(actual_path, 4096);
	if (chdir(argv[1]) == -1)
	{
		ft_fprintf(2, "cd: %s: %s\n", argv[1], strerror(errno));
		return (EXIT_FAILURE);
	}
	if (ft_getenv(*env, "OLDPWD") && !add_to_env(env, "OLDPWD=", actual_path))
		return (EXIT_FAILURE);
	getcwd(actual_path, 4096);
	if (ft_getenv(*env, "PWD") && !add_to_env(env, "PWD=", actual_path))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
