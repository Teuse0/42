/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:35:50 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 15:23:17 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"

static int	wait_cmds(t_cmd **cmds, t_files *files)
{
	int	exit_status;
	int	i;

	exit_status = g_exit_status;
	i = 0;
	while (cmds[i])
	{
		if (is_cmd_invalid_redir(cmds, files, i))
			exit_status = cmd_error_code(cmds[i]);
		else if (is_builtin(cmds[i]->args[0]))
			exit_status = files->builtins_ret_val;
		else if (cmds[i]->path)
			exit_status = wait_cmd(cmds[i]);
		else
			exit_status = cmd_error_code(cmds[i]);
		i++;
	}
	if (files->output != 1 && !check_file(files->output_path, W_OK, 0))
		return (1);
	return (exit_status);
}

static int	fork_cmd(t_cmd **cmds, t_files *files, int cmd_number, int i)
{
	signal(SIGINT, signal_cmd2);
	signal(SIGQUIT, signal_cmd2);
	cmds[i]->pid = fork();
	if (cmds[i]->pid == -1)
	{
		perror("minishell");
		return (0);
	}
	else if (cmds[i]->pid == 0)
	{
		signal(SIGINT, signal_cmd2);
		signal(SIGQUIT, signal_cmd2);
		exec_dup2_in(files, i);
		exec_dup2_out(files, cmd_number, i);
		close_pipe_fds(files->pipe_fds);
		execve(cmds[i]->path, cmds[i]->args, *files->envp);
		exit(EXIT_FAILURE);
	}
	return (1);
}

static int	check_file_at(t_files *files, char *lim, int cmd_number, int i)
{
	if (i == 0 && !lim && files->input != 0
		&& !check_file(files->input_path, R_OK, 1))
		return (1);
	if (i == cmd_number - 1 && files->output != 1
		&& !check_file(files->output_path, W_OK, 1))
		return (1);
	return (0);
}

static int	loop_cmds(t_files *files, t_cmd **cmds, int cmd_number, char *lim)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if (files->do_exit)
			break ;
		if (!repipe(files->pipe_fds[i % 2]))
			return (0);
		if (check_file_at(files, lim, cmd_number, i)
			|| exec_builtins(files, cmds[i], cmd_number, i)
			|| (!cmds[i]->path && cmd_error(cmds[i])))
		{
			i++;
			continue ;
		}
		if (!fork_cmd(cmds, files, cmd_number, i))
			return (0);
		i++;
	}
	return (1);
}

int	run_cmds(t_files *files, t_cmd **cmds, int cmd_number, char *lim)
{
	int	exit_status;

	if (!open_pipes(files->pipe_fds))
		return (EXIT_FAILURE);
	if (lim)
		here_doc(lim, files->pipe_fds[1][1]);
	if (!loop_cmds(files, cmds, cmd_number, lim))
		return (EXIT_FAILURE);
	close_pipe_fds(files->pipe_fds);
	exit_status = wait_cmds(cmds, files);
	return (exit_status);
}
