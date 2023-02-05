/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:08:26 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 19:42:59 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec(char ***raw_cmds, char ***env, int *error_flag)
{
	t_cmd			**cmds;
	char			*lim;
	int				do_exit;
	int				i;

	do_exit = 0;
	i = 0;
	while (raw_cmds[i] && !do_exit)
	{
		do_useless_heredocs(raw_cmds + i);
		if (!do_useless_redir(raw_cmds + i))
		{
			i++;
			continue ;
		}
		remove_trailing_pipes(raw_cmds + i);
		lim = get_lim(raw_cmds[i]);
		cmds = lst_to_cmd(raw_cmds[i], *env, error_flag);
		do_exit = exec_cmd(cmds, lim, env,
				ft_create_redir(raw_cmds[i], i == 0, raw_cmds[i + 1] == NULL));
		free_stuff(lim, cmds);
		i++;
	}
	free_sep_cmds(raw_cmds);
	return (do_exit);
}

int	parse_and_exec_cmd(char ***env, char *str)
{
	char	***cmds;
	int		error_flag;

	error_flag = 0;
	cmds = ft_pars(str, *env);
	if (!cmds)
		return (0);
	return (exec(cmds, env, &error_flag));
}
