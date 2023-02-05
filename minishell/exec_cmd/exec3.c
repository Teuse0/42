/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:35:50 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 14:33:05 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"

int	wait_cmd(t_cmd *cmd)
{
	int	status;
	int	sig;

	waitpid(cmd->pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
			return (130);
		else if (sig == SIGQUIT)
			return (131);
		else
			return (sig);
	}
	return (0);
}

int	is_cmd_invalid_redir(t_cmd **cmds, t_files *files, int i)
{
	if (i == 0 && files->input_path
		&& !check_file(files->input_path, R_OK, 0))
		return (1);
	else if (!cmds[i + 1] && files->output_path
		&& !check_file(files->output_path, W_OK, 0))
		return (1);
	return (0);
}
