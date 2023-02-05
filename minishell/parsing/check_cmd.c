/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:54:59 by broy              #+#    #+#             */
/*   Updated: 2023/01/17 14:02:55 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_quote(char *str)
{
	int	j;
	int	quote;

	j = 0;
	quote = 0;
	while (str[j])
	{
		if (str[j] == '"')
		{
			if (quote == 0)
				quote = 1;
			else if (quote == 1)
				quote = 0;
		}
		if (str[j] == '\'')
		{
			if (quote == 0)
				quote = 2;
			else if (quote == 2)
				quote = 0;
		}
		j++;
	}
	return (quote);
}

static int	ft_check_simple(char *str, int i)
{
	if (str[i] == '>' || str[i] == '<')
	{
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 0 || str[i] == '|'
			|| str[i] == '<' || str[i] == '>')
			return (1);
	}
	else if (str[i] == '|')
	{
		i++;
		while (str[i] == ' ')
			i++;
		if (str[i] == 0 || str[i] == '|')
			return (1);
	}
	return (0);
}

static int	ft_check_double(char *str, int i)
{
	i = i + 1;
	while (str[i] == ' ')
		i++;
	if (str[i + 1] == 0 || str[i + 1] == '|' || str[i + 1] == '<'
		|| str[i + 1] == '>')
		return (1);
	return (0);
}

static int	ft_check_quote(char *str, int i)
{
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
	}
	else if (str[i] == '"')
	{
		i++;
		while (str[i] != '"')
			i++;
	}
	return (i);
}

int	ft_check_cmd(char *str)
{
	int	i;

	i = 0;
	if (ft_quote(str))
		return (1);
	if (ft_check_spaces(str))
		return (4);
	while (str[i])
	{
		i = ft_check_quote(str, i);
		if (str[i] == '|' || (str[i] == '<' && str[i + 1] != '<')
			|| (str[i] == '>' && str[i + 1] != '>'))
		{
			if (ft_check_simple(str, i))
				return (2);
		}
		else if ((str[i] == '<' && str[i + 1] == '<')
			|| (str[i] == '>' && str[i + 1] == '>'))
			if (ft_check_double(str, i))
				return (3);
		i++;
	}
	return (0);
}
