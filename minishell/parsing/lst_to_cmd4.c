/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:56:15 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 19:56:34 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_join_cmds(char **tmp, char **cmds, int *k, int *j)
{
	cmds[*k] = ft_strdup(tmp[*j]);
	while (tmp[++(*j)])
	{
		cmds[*k] = ft_strjoin_free2(cmds[*k], " ");
		cmds[*k] = ft_strjoin_free2(cmds[*k], tmp[*j]);
	}
	(*k)++;
}

char	**ft_get_sep_cmds_2(char **arg, char **env,
			int *error_flag, char **cmds)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	k = 0;
	i = -1;
	while (arg[++i])
	{
		tmp = ft_split_quotes(arg[i], ' ');
		j = 0;
		while (tmp[j])
		{
			if (is_builtin(tmp[j]) || (ft_is_cmd(tmp[j], env, error_flag)
					&& (i == 0 || (i != 0 && ft_strncmp(arg[i - 1], "<", 1)))))
				ft_join_cmds(tmp, cmds, &k, &j);
			else
				cmds[k++] = ft_strdup(tmp[j++]);
		}
		ft_free_split(tmp);
	}
	return (cmds);
}

char	**ft_get_sep_cmds(char **arg, int *error_flag, char **env)
{
	char	**cmds;

	cmds = ft_calloc(ft_size_cmds(arg, error_flag, env) + 1, sizeof(char *));
	if (!cmds)
		return (NULL);
	cmds = ft_get_sep_cmds_2(arg, env, error_flag, cmds);
	return (cmds);
}

int	ft_size_lst(char **arg, int *error_flag, char **env)
{
	int		i;
	int		size;
	char	*cmd;

	i = 0;
	size = 0;
	while (arg[i])
	{
		cmd = ft_get_cmd(arg[i], env, error_flag);
		if (cmd)
			size++;
		free(cmd);
		i++;
	}
	return (size);
}

t_cmd	*ft_get_lst_heredoc(char *arg, char **env, char *cmd, int *error_flag)
{
	t_cmd	*lst_cmd;

	lst_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!lst_cmd)
		return (NULL);
	lst_cmd->args = ft_get_args(arg);
	if (cmd)
		lst_cmd->path = cmd_path(env, cmd, error_flag);
	else
		lst_cmd->path = NULL;
	lst_cmd->error_flag = *error_flag;
	return (lst_cmd);
}
