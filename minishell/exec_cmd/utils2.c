/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:19:42 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 14:31:06 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"

int	check_file(char *path, int option, int show_error)
{
	if (access(path, option))
	{
		if (show_error)
			perror_file(path);
		return (0);
	}
	return (1);
}

void	exec_dup2_in(t_files *files, int i)
{
	if (i == 0 && files->input == 0 && !files->is_lim)
		return ;
	if (i == 0 && files->input_path)
		dup2(files->input, 0);
	else
		dup2(files->pipe_fds[(i + 1) % 2][0], 0);
}

void	exec_dup2_out(t_files *files, int cmd_number, int i)
{
	if (i == cmd_number - 1 && files->output == 1)
		return ;
	if (i == cmd_number - 1)
		dup2(files->output, 1);
	else
		dup2(files->pipe_fds[i % 2][1], 1);
}

void	signal_cmd2(int sig)
{
	if (sig == 2)
		printf("\n");
	if (sig == SIGQUIT)
		write(2, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
}
