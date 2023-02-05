/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:46:26 by broy              #+#    #+#             */
/*   Updated: 2023/02/03 19:41:45 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_lim(char **str)
{
	char	*lim;
	int		size;
	int		i;

	if (str[0] && ft_strncmp(str[0], "<<", 3) == 0)
	{
		size = 0;
		while (str[1][size] && str[1][size] != ' ')
			size++;
		lim = malloc(sizeof(char) * (size + 1));
		if (!lim)
			return (NULL);
		i = 0;
		while (i < size)
		{
			lim[i] = str[1][i];
			i++;
		}
		lim[i] = '\0';
		return (lim);
	}
	else
		return (NULL);
}

t_redirection	ft_create_redir(char **str, int is_first, int is_last)
{
	t_redirection	redir;
	int				i;

	i = 0;
	init_redir(&redir);
	if (!ft_strncmp(str[0], "<", 2))
		str[1] = ft_change(str[1]);
	while (str[i])
	{
		if (!ft_strncmp(str[i], "<", 2))
			redir.in = str[i + 1];
		if (!ft_strncmp(str[i], ">", 2) && str[i + 1])
			redir.out = str[i + 1];
		if (!ft_strncmp(str[i], ">>", 3) && str[i + 1])
		{
			redir.is_append = 1;
			redir.out = str[i + 1];
		}
		i++;
	}
	if (!is_first && !redir.in)
		redir.in = ft_strdup("/dev/null");
	if (!is_last && !redir.out)
		redir.out = ft_strdup("/dev/null");
	return (redir);
}

void	ft_free_all(t_cmd **cmds, char **str, char ***raw_cmds)
{
	int	i;
	int	j;

	i = 0;
	while (raw_cmds[i])
	{
		j = 0;
		free(str[i]);
		while (raw_cmds[i][j])
			free(raw_cmds[i][j++]);
		free(raw_cmds[i]);
		j = 0;
		if (cmds)
		{
			while (cmds[i]->args[j])
				free(cmds[i]->args[j++]);
			free(cmds[i]->args);
			free(cmds[i]->path);
			free(cmds[i]);
		}
		i++;
	}
	free(raw_cmds);
	free(str);
	free(cmds);
}
