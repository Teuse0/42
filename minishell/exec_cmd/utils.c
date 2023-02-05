/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:19:42 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/01 21:16:44 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"

int	repipe(int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (pipe(pipe_fd) == -1)
	{
		perror("minishell");
		return (0);
	}
	return (1);
}

int	open_pipes(int pipe_fds[2][2])
{
	if (pipe(pipe_fds[0]) == -1)
	{
		perror("minishell");
		return (0);
	}
	if (pipe(pipe_fds[1]) == -1)
	{
		close(pipe_fds[0][0]);
		close(pipe_fds[0][1]);
		perror("minishell");
		return (0);
	}
	return (1);
}

void	close_pipe_fds(int pipe_fds[2][2])
{
	close(pipe_fds[0][0]);
	close(pipe_fds[0][1]);
	close(pipe_fds[1][0]);
	close(pipe_fds[1][1]);
}

int	cmd_error(t_cmd *cmd)
{
	if (cmd->error_flag == 2)
	{
		if (ft_strncmp(cmd->args[0], "./", 2) == 0 || cmd->args[0][0] == '/'
			|| ft_strncmp(cmd->args[0], "../", 3) == 0)
			ft_fprintf(2, "minishell: %s: No such file or directory\n",
				cmd->args[0]);
		else
			ft_fprintf(2, "minishell: %s: command not found\n", cmd->args[0]);
	}
	else if (cmd->error_flag == 13)
		ft_fprintf(2, "minishell: %s: Permission denied\n", cmd->args[0]);
	else if (cmd->error_flag == 50)
		ft_fprintf(2, "minishell: %s: Is a directory\n", cmd->args[0]);
	return (1);
}

int	cmd_error_code(t_cmd *cmd)
{
	if (cmd->error_flag == 75)
		return (0);
	if (cmd->error_flag == 13 || cmd->error_flag == 50)
		return (126);
	return (127);
}
