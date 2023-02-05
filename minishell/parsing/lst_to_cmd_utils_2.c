/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:00:55 by broy              #+#    #+#             */
/*   Updated: 2023/02/03 17:00:56 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_size_cmd(char *arg)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (arg[i] && arg[i] != ' ')
	{
		if (arg[i] == '\'' || arg[i] == '"')
		{
			i++;
			while (arg[i] != '"' && arg[i++] != '\'')
				size++;
		}
		else
			size++;
		if (arg[i])
			i++;
	}
	return (size);
}

char	*copy(char *arg, int i)
{
	char	*ret;
	int		j;
	int		size;

	size = 0;
	i++;
	j = i;
	while (arg[j++])
		size++;
	ret = malloc(size + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (arg[i])
	{
		ret[j] = arg[i];
		j++;
		i++;
	}
	ret[j] = 0;
	free(arg);
	return (ret);
}
