/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:14:01 by tguerin           #+#    #+#             */
/*   Updated: 2023/01/17 14:05:56 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_sep_cmds(char ***sep_cmds)
{
	int	i;

	i = 0;
	while (sep_cmds[i])
	{
		ft_split_free(sep_cmds[i]);
		i++;
	}
	free(sep_cmds);
}

static int	sep(char **cmds, int index)
{
	if (index >= 2 && cmds[index][0] == '|' && cmds[index - 2][0] == '>')
		return (1);
	if (cmds[index + 1] != NULL
		&& cmds[index][0] == '|' && cmds[index + 1][0] == '<')
		return (1);
	return (0);
}

static int	sep_cmds_size(char **cmds)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (cmds[i])
	{
		size += sep(cmds, i);
		i++;
	}
	return (size);
}

static int	slice_sep_cmds(char **cmds, char ***sep_cmds)
{
	int		old_i;
	int		i;
	int		j;

	old_i = 0;
	i = 0;
	j = 0;
	while (cmds[i])
	{
		if (sep(cmds, i))
		{
			sep_cmds[j] = ft_split_slice(cmds, old_i, i);
			if (!sep_cmds[j])
				return (0);
			old_i = i;
			j++;
		}
		i++;
	}
	sep_cmds[j] = ft_split_slice(cmds, old_i, i);
	if (!sep_cmds[j])
		return (0);
	sep_cmds[j + 1] = NULL;
	return (1);
}

char	***sep_cmds(char **cmds)
{
	char	***sep_cmds;

	if (!cmds || !cmds[0])
		return (NULL);
	sep_cmds = malloc(sizeof(*sep_cmds) * (sep_cmds_size(cmds) + 2));
	if (!sep_cmds)
		return (NULL);
	if (!slice_sep_cmds(cmds, sep_cmds))
	{
		free_sep_cmds(sep_cmds);
		return (NULL);
	}
	return (sep_cmds);
}
