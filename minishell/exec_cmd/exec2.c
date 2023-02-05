/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:41:59 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 16:08:32 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"

static void	exec_builtin(t_files *files, t_cmd *cmd, int infos[2],
	int (*func)(int argc, char **argv, char ***env))
{
	int	stdin_cpy;
	int	stdout_cpy;

	stdin_cpy = dup(0);
	stdout_cpy = dup(1);
	exec_dup2_in(files, infos[1]);
	exec_dup2_out(files, infos[0], infos[1]);
	files->builtins_ret_val = (*func)(ft_split_size(cmd->args), cmd->args,
			files->envp);
	if (files->builtins_ret_val == -1)
		files->builtins_ret_val = 1;
	else if (&exit_ == func)
		files->do_exit = 1;
	dup2(stdin_cpy, 0);
	dup2(stdout_cpy, 1);
	close(stdin_cpy);
	close(stdout_cpy);
}

int	exec_builtins(t_files *files, t_cmd *cmd, int cmd_number, int i)
{
	int	infos[2];

	infos[0] = cmd_number;
	infos[1] = i;
	if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		exec_builtin(files, cmd, infos, &cd);
	else if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		exec_builtin(files, cmd, infos, &echo);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		exec_builtin(files, cmd, infos, &env);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		exec_builtin(files, cmd, infos, &export);
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		exec_builtin(files, cmd, infos, &pwd);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		exec_builtin(files, cmd, infos, &unset);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		exec_builtin(files, cmd, infos, &exit_);
	else
		return (0);
	return (1);
}
