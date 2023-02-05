/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:57:11 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 20:36:03 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	**ft_make_cmds_heredoc(char **arg, char **env, int *error_flag,
	char **cmds)
{
	int		i;
	int		size;
	char	*cmd;
	t_cmd	**lst_cmd;

	lst_cmd = malloc(sizeof(t_cmd) * (ft_size_lst(arg, error_flag, env) + 1));
	if (!lst_cmd)
		return (NULL);
	size = 0;
	i = 1;
	while (arg[i])
	{
		cmd = ft_get_cmd(arg[i], env, error_flag);
		if ((cmd || (i >= 1 && cmds[i + 1])) && ft_strncmp(arg[i], "|", 1))
		{
			lst_cmd[size] = ft_get_lst_heredoc(arg[i], env, cmd, error_flag);
			size++;
		}
		free(cmd);
		i++;
	}
	lst_cmd[size] = NULL;
	ft_free_split(cmds);
	return (lst_cmd);
}

t_cmd	**ft_lst_heredeoc(char **arg, char **env, int *error_flag, char **cmds)
{
	int	i;

	i = 0;
	while (arg[1][i] && arg[1][i] != ' ')
		i++;
	if (arg[1][i])
		arg[1] = copy(arg[1], i);
	return (ft_make_cmds_heredoc(arg, env, error_flag, cmds));
}

int	ft_condition_2(char **cmds, int i, char **env, int *error_flag)
{
	return ((i == 0 && ((ft_strncmp(cmds[i], "|", 1)
					&& ft_strncmp(cmds[i], ">>", 2)
					&& ft_strncmp(cmds[i], ">", 1)
					&& ft_strncmp(cmds[i], "<", 1)))) || !cmds[1]
		|| (ft_strncmp(cmds[i], "|", 1)
			&& ft_strncmp(cmds[i], ">>", 2) && ft_strncmp(cmds[i], ">", 1)
			&& ft_strncmp(cmds[i], "<", 1)
			&& (i != 0 && ((ft_is_cmd(cmds[i - 1], env, error_flag)
						|| !ft_strncmp(cmds[i - 1], "|", 1))
					&& ft_strncmp(cmds[i - 1], ">", 1)
					&& ft_strncmp(cmds[i - 1], "<", 1)))));
}

int	ft_condition_1(char **cmds, int i, char *cmd)
{
	return (cmd && (i == 0 || (cmds[i + 1]
				&& (!ft_strncmp(cmds[i + 1], ">", 1)))
			|| (i != 0 && (ft_strncmp(cmds[i - 1], "<", 1)))));
}
