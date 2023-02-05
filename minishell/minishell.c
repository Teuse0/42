/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:03:25 by broy              #+#    #+#             */
/*   Updated: 2023/02/02 04:57:34 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

void	signal_cmd(int sig)
{
	g_exit_status += sig;
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", ft_strlen("Quit (core dumped)\n"));
		g_exit_status = 131;
	}
}

void	ft_error_cmd(int err)
{
	if (err == 1)
		ft_fprintf(2, "minishell: missing quote\n");
	if (err == 2)
		ft_fprintf(2, "minishell: syntax error\n");
	if (err == 3)
		ft_fprintf(2, "minishell: syntax error near unexpected "
			"token `newline\'\n");
}

static void	loop(char ***env)
{
	char	*str;

	while (1)
	{
		signal(SIGINT, signal_cmd);
		signal(SIGQUIT, SIG_IGN);
		str = readline("minishell$> ");
		if (!str)
		{
			free(str);
			printf("exit\n");
			break ;
		}
		add_history(str);
		if (!ft_check_cmd(str) && parse_and_exec_cmd(env, str))
		{
			free(str);
			break ;
		}
		else if (ft_check_cmd(str))
			ft_error_cmd(ft_check_cmd(str));
		free(str);
	}
}

int	main(int ac, char **av, char **envp)
{
	char	**env;

	if (!ac && !av)
		return (0);
	g_exit_status = 0;
	signal(SIGINT, signal_cmd);
	signal(SIGQUIT, SIG_IGN);
	env = ft_split_dup(envp);
	if (!env)
		return (0);
	loop(&env);
	ft_split_free(env);
	return (g_exit_status);
}
