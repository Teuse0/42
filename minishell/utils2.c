/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:35:41 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 19:40:29 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_regular_file(const char *path, int *error_flag)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) || !S_ISREG(path_stat.st_mode))
	{
		*error_flag = 50;
		g_exit_status = 126;
		return (0);
	}
	return (1);
}

int	is_builtin(char *cmd_name)
{
	char	**builtins;
	int		i;

	builtins = ft_split("cd,echo,env,pwd,unset,export,exit", ',');
	if (!builtins)
		return (0);
	i = 0;
	while (builtins[i])
	{
		if (ft_strncmp(builtins[i], cmd_name, ft_strlen(cmd_name) + 1) == 0)
		{
			ft_split_free(builtins);
			return (1);
		}
		i++;
	}
	ft_split_free(builtins);
	return (0);
}

void	fake_open(const char *file_name, int is_append)
{
	int	fd;

	if (is_append)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(fd);
}

void	free_stuff(char *lim, t_cmd **cmds)
{
	free(lim);
	free_cmds(cmds);
}

void	init_redir(t_redirection *redirection)
{
	redirection->in = NULL;
	redirection->out = NULL;
	redirection->is_append = 0;
}
