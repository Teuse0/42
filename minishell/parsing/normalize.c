/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:14:01 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/03 17:58:47 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	order_redir(char ***raw_cmd)
{
	char	*cmd;
	char	*tmp;
	int		i;

	i = 1;
	while ((*raw_cmd)[i])
	{
		if (ft_strncmp((*raw_cmd)[i], "<", 2) == 0
			&& ft_strchr("|<>", (*raw_cmd)[i - 1][0]) == NULL)
		{
			cmd = (*raw_cmd)[i - 1];
			(*raw_cmd)[i - 1] = (*raw_cmd)[i];
			tmp = ft_strjoin((*raw_cmd)[i + 1], " ");
			(*raw_cmd)[i] = ft_strjoin(tmp, cmd);
			free(tmp);
			free(cmd);
			ft_split_remove(raw_cmd, i + 1);
		}
		i++;
	}
}

void	order_heredeocs(char ***raw_cmd)
{
	char	*tmp;
	int		cmd_index;
	int		i;

	cmd_index = -1;
	i = 1;
	while ((*raw_cmd)[i])
	{
		if (cmd_index == -1 && ft_strncmp((*raw_cmd)[i], "<<", 3) == 0
			&& (i < 2 || ft_strncmp((*raw_cmd)[i - 2], "<<", 3) != 0)
			&& ft_strchr("|<>", (*raw_cmd)[i - 1][0]) == NULL)
			cmd_index = i - 1;
		if (cmd_index != -1 && ft_strncmp((*raw_cmd)[i], "<<", 3) == 0
			&& (!(*raw_cmd)[i + 2] || ft_strncmp((*raw_cmd)[i + 2], "<<", 3)))
		{
			tmp = ft_strjoin((*raw_cmd)[i + 1], " ");
			free((*raw_cmd)[i + 1]);
			(*raw_cmd)[i + 1] = ft_strjoin(tmp, (*raw_cmd)[cmd_index]);
			free(tmp);
			ft_split_remove(raw_cmd, cmd_index);
			cmd_index = -1;
		}
		i++;
	}
}

int	do_useless_heredocs(char ***cmd)
{
	int	i;

	i = 0;
	while ((*cmd)[i] && ft_split_count(*cmd, "<<") > 1)
	{
		if (ft_strncmp((*cmd)[i], "<<", 3) == 0)
		{
			here_doc((*cmd)[i + 1], -1);
			if (!ft_split_remove(cmd, i) || !ft_split_remove(cmd, i))
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	do_useless_redir(char ***cmd)
{
	int	i;

	i = 0;
	while ((*cmd)[i]
		&& ft_split_count(*cmd, ">") + ft_split_count(*cmd, ">>") > 1)
	{
		if ((*cmd)[i][0] == '>')
		{
			if (access((*cmd)[i + 1], W_OK) != 0
				&& access((*cmd)[i + 1], F_OK) == 0)
			{
				ft_fprintf(2, "minishell: %s: Permission denied\n",
					(*cmd)[i + 1]);
				return (0);
			}
			fake_open((*cmd)[i + 1], ft_strncmp((*cmd)[i], ">>", 3) == 0);
			if (!ft_split_remove(cmd, i) || !ft_split_remove(cmd, i))
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	remove_trailing_pipes(char ***cmd)
{
	int	max_index;

	if ((*cmd)[0][0] == '|')
		if (!ft_split_remove(cmd, 0))
			return (0);
	max_index = ft_split_size(*cmd) - 1;
	if ((*cmd)[max_index][0] == '|')
		if (!ft_split_remove(cmd, max_index))
			return (0);
	return (1);
}
