/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:12:48 by broy              #+#    #+#             */
/*   Updated: 2023/02/03 20:36:22 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*ft_get_cmds(char *args, char *cmd, int *error_flag, char **env)
{
	t_cmd	*lst_cmd;

	lst_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!lst_cmd)
		return (NULL);
	lst_cmd->args = ft_get_args(args);
	lst_cmd->path = cmd_path(env, cmd, error_flag);
	lst_cmd->error_flag = *error_flag;
	return (lst_cmd);
}

t_cmd	*ft_get_cmds_2(char *args, int *error_flag)
{
	t_cmd	*lst_cmd;

	lst_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!lst_cmd)
		return (NULL);
	lst_cmd->args = ft_get_args(args);
	lst_cmd->path = NULL;
	lst_cmd->error_flag = *error_flag;
	return (lst_cmd);
}

t_cmd	**lst_to_cmd_2(t_cmd **lst_cmd, char **cmds,
				int *error_flag, char **env)
{
	int		j;
	int		i;
	char	*cmd;

	j = 0;
	i = 0;
	while (cmds[i])
	{
		cmd = ft_get_cmd(cmds[i], env, error_flag);
		if (ft_condition_1(cmds, i, cmd))
		{
			lst_cmd[j] = ft_get_cmds(cmds[i], cmd, error_flag, env);
			j++;
		}
		else if (ft_condition_2(cmds, i, env, error_flag))
		{
			lst_cmd[j] = ft_get_cmds_2(cmds[i], error_flag);
			j++;
		}
		free(cmd);
		i++;
	}
	lst_cmd[j] = NULL;
	return (lst_cmd);
}

t_cmd	**lst_to_cmd(char **arg, char **env, int *error_flag)
{
	t_cmd	**lst_cmd;
	char	**cmds;

	cmds = ft_get_sep_cmds(arg, error_flag, env);
	if (!ft_strncmp(arg[0], "<<", 2))
		return (ft_lst_heredeoc(arg, env, error_flag, cmds));
	lst_cmd = malloc(sizeof(t_cmd) * (ft_size_lst(arg, error_flag, env) + 1));
	if (!lst_cmd)
		return (NULL);
	lst_cmd = lst_to_cmd_2(lst_cmd, cmds, error_flag, env);
	ft_free_split(cmds);
	return (lst_cmd);
}
