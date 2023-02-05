/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:15:08 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 16:08:54 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMD_H
# define EXEC_CMD_H

# include "../minishell.h"
# include "../builtins/builtins.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_files
{
	int		pipe_fds[2][2];
	char	*input_path;
	int		input;
	char	*output_path;
	int		output;
	char	***envp;
	int		is_lim;
	int		builtins_ret_val;
	int		do_exit;
}		t_files;

void	perror_file(char *file_path);
char	*get_shell(void);
void	free_cmds(t_cmd **cmds);
int		repipe(int pipe_fd[2]);
void	close_pipe_fds(int pipe_fds[2][2]);
void	perror_shell(void);
int		open_pipes(int pipe_fds[2][2]);
int		check_file(char *path, int option, int show_error);
int		run_cmds(t_files *files, t_cmd **cmds, int cmd_number, char *lim);
int		exec_builtins(t_files *files, t_cmd *cmd, int cmd_number, int i);
void	exec_dup2_out(t_files *files, int cmd_number, int i);
void	exec_dup2_in(t_files *files, int i);
int		cmd_error(t_cmd *cmd);
int		cmd_error_code(t_cmd *cmd);
int		wait_cmd(t_cmd *cmd);
int		is_cmd_invalid_redir(t_cmd **cmds, t_files *files, int i);

#endif
