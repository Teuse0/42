/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:52:25 by broy              #+#    #+#             */
/*   Updated: 2022/07/24 23:50:06 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

char	**ft_input(char **argv, int *argc, char **input)
{
	char		**split;
	int			j;
	int			i;
	int			end;

	input = malloc(501 * sizeof(char *));
	end = 0;
	j = 1;
	i = 0;
	while (argv[j] != NULL)
	{
		split = ft_split(argv[j], ' ');
		i = 0;
		while (split[i] != NULL)
		{
			input[end] = ft_strdup(split[i]);
			i++;
			end++;
		}
		ft_free_array(split);
		j++;
	}
	*argc = end;
	input[end] = NULL;
	return (input);
}

static char	*ft_join(char **av, int len)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(len);
	i = -1;
	len = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			str[len] = av[i][j];
			len++;
		}
		str[len] = ' ';
		len++;
	}
	str[len - 1] = 0;
	return (str);
}

char	*ft_parse(char **av, t_all *all)
{
	int			i;
	int			j;
	int			len;
	char		*str;

	i = -1;
	len = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == 0)
		{
			all->check = 0;
			ft_exit_error(all);
		}
		while (av[i][j++])
			len++;
		len++;
	}
	str = ft_join(av, len);
	return (str);
}
