/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:36:06 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 02:16:48 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_line(char *line, int write_fd)
{
	ft_putstr_fd(line, write_fd);
	ft_putchar_fd('\n', write_fd);
}

static void	signal_here_doc(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		g_exit_status = 130;
		close(0);
	}
}

static void	read_lines(char *lim, int write_fd)
{
	char	*line;
	int		i;

	i = 1;
	while (1)
	{
		line = readline("> ");
		if (g_exit_status == 130)
			break ;
		if (!line)
		{
			ft_fprintf(2, HERE_DOC_EOL, i, lim);
			break ;
		}
		if (ft_strncmp(line, lim, ft_strlen(lim)) == 0
			&& ft_strlen(lim) == ft_strlen(line))
		{
			free(line);
			break ;
		}
		if (write_fd >= 0)
			write_line(line, write_fd);
		free(line);
		i++;
	}
}

/// @param write_fd if less than 0 write nothing
void	here_doc(char *lim, int write_fd)
{
	int	stdin_cpy;

	signal(SIGINT, signal_here_doc);
	signal(SIGQUIT, SIG_IGN);
	stdin_cpy = dup(0);
	read_lines(lim, write_fd);
	dup2(stdin_cpy, 0);
	close(stdin_cpy);
}
