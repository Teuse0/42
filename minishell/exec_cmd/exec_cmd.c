/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:14:56 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 19:36:41 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"

static void	init_files(t_redirection redirection, t_files *files, char *lim)
{
	int	open_mod;

	files->input_path = NULL;
	if (!lim)
		files->input_path = redirection.in;
	files->input = 0;
	if (files->input_path)
		files->input = open(files->input_path, O_RDONLY);
	files->output_path = redirection.out;
	if (redirection.is_append)
		open_mod = O_WRONLY | O_APPEND | O_CREAT;
	else
		open_mod = O_WRONLY | O_TRUNC | O_CREAT;
	files->output = 1;
	if (files->output_path)
		files->output = open(files->output_path, open_mod, 0644);
}

static void	close_files(t_files *files)
{
	if (files->input != -1 && files->input != 0)
		close(files->input);
	if (files->output != -1 && files->output != 1)
		close(files->output);
}

int	exec_cmd(t_cmd **cmds, char *lim, char ***envp, t_redirection redirection)
{
	t_files	files;
	int		cmd_nb;

	g_exit_status = 0;
	files.do_exit = 0;
	if (!cmds)
		return (1);
	files.is_lim = 0;
	if (lim)
		files.is_lim = 1;
	cmd_nb = 0;
	while (cmds[cmd_nb])
		cmd_nb += 1;
	files.envp = envp;
	init_files(redirection, &files, lim);
	g_exit_status = run_cmds(&files, cmds, cmd_nb, lim);
	close_files(&files);
	if (redirection.in && ft_strncmp(redirection.in, "/dev/null", 10) == 0)
		free(redirection.in);
	if (redirection.out && ft_strncmp(redirection.out, "/dev/null", 10) == 0)
		free(redirection.out);
	return (files.do_exit);
}
