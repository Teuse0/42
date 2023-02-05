/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:24:57 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/01 21:16:00 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**get_path(char **env)
{
	const char	*raw_path;
	char		**path;

	raw_path = ft_getenv(env, "PATH");
	if (!raw_path)
		return (ft_calloc(1, sizeof(char *)));
	path = ft_split(raw_path + 5, ':');
	if (!path)
	{
		perror("minishell");
		return (NULL);
	}
	return (path);
}

static char	*parse_cmd_path(char *path, char *cmd, int *error_flag)
{
	char	*tmp;
	char	*cmd_path;

	if (path[0] != '\0')
		tmp = ft_strjoin(path, "/");
	else
		tmp = ft_strdup(path);
	if (!tmp)
	{
		*error_flag = 1;
		return (NULL);
	}
	cmd_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!cmd_path)
	{
		*error_flag = 1;
		return (NULL);
	}
	if (access(cmd_path, X_OK) == 0 && is_regular_file(cmd_path, error_flag))
		return (cmd_path);
	if (*error_flag != ENOENT && *error_flag != 50)
		*error_flag = errno;
	free(cmd_path);
	return (NULL);
}

char	*find_in_path(char **path, char *cmd, int *error_flag)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (path[i])
	{
		cmd_path = parse_cmd_path(path[i], cmd, error_flag);
		if (cmd_path || *error_flag == 1)
			return (cmd_path);
		i++;
	}
	if (*error_flag == 0)
		*error_flag = 2;
	return (NULL);
}

char	*cmd_path(char **env, char *cmd, int *error_flag)
{
	char	**path;
	char	*cmd_path;

	path = get_path(env);
	if (!path)
	{
		*error_flag = 1;
		return (NULL);
	}
	if (!cmd[0])
	{
		*error_flag = 75;
		cmd_path = NULL;
	}
	else if (ft_strncmp(cmd, "./", 2) == 0)
		cmd_path = parse_cmd_path("", cmd + 2, error_flag);
	else if (ft_strncmp(cmd, "../", 3) == 0)
		cmd_path = parse_cmd_path("", cmd + 3, error_flag);
	else if (ft_strncmp(cmd, "/", 1) == 0)
		cmd_path = parse_cmd_path("", cmd, error_flag);
	else
		cmd_path = find_in_path(path, cmd, error_flag);
	ft_split_free(path);
	return (cmd_path);
}

void	free_cmds(t_cmd **cmds)
{
	int	i;

	if (!cmds)
		return ;
	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] || cmds[i]->args)
			ft_split_free(cmds[i]->args);
		free(cmds[i]->path);
		free(cmds[i]);
		i++;
	}
	free(cmds);
}
