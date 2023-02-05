/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:12:48 by broy              #+#    #+#             */
/*   Updated: 2023/02/02 05:13:30 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_args_3(char *str, char *args, int i)
{
	int	k;

	k = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			while (str[i] == '\'' || str[i] == '"')
				i++;
			args[k++] = str[i++];
			while (str[i] && str[i] != '"' && str[i] != '\'')
				args[k++] = str[i++];
		}
		if (str[i])
			args[k++] = str[i++];
	}
	return (i);
}

static char	**ft_get_args_2(char *str, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && str[i + 1] == '\'') || (str[i] == '"'
				&& str[i + 1] == '"'))
		{
			i += 2;
			if (!str[i])
				return (args);
			if (str[i] == ' ')
				i++;
		}
		args[j] = ft_calloc(ft_size_arg(str, i) + 1, 1);
		if (!args[j])
			return (NULL);
		i = ft_get_args_3(str, args[j], i);
		if (str[i] != 0)
			i++;
		j++;
	}
	return (args);
}

char	**ft_get_args(char *str)
{
	char	**args;
	int		i;

	args = ft_calloc((ft_nbr_args(str)), sizeof(args));
	if (!args)
		return (NULL);
	if (!str || str[0] == 0)
	{
		args[0] = malloc(1);
		args[0][0] = 0;
		return (args);
	}
	ft_get_args_2(str, args);
	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "\"\"", 3) && ft_strncmp(args[i], "''", 3))
		{
			args[i] = ft_strtrim_free(args[i], "'");
			args[i] = ft_strtrim_free(args[i], "\"");
		}
		i++;
	}
	return (args);
}

char	*ft_get_cmd_2(char *arg, char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] && arg[i] != ' ')
	{
		if (arg[i] == '\'' || arg[i] == '"')
		{
			i++;
			while (arg[i] != '"' && arg[i] != '\'')
				cmd[j++] = arg[i++];
		}
		else
			cmd[j] = arg[i];
		j++;
		i += arg[i] != 0;
	}
	return (cmd);
}

char	*ft_get_cmd(char *arg, char **env, int *error_flag)
{
	char	*cmd;

	cmd = ft_calloc(ft_size_cmd(arg) + 1, sizeof(*cmd));
	if (!cmd)
		return (NULL);
	cmd = ft_get_cmd_2(arg, cmd);
	if (ft_is_cmd(cmd, env, error_flag))
		return (cmd);
	free(cmd);
	return (NULL);
}
