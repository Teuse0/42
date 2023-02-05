/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:45:50 by tguerin           #+#    #+#             */
/*   Updated: 2023/02/02 22:04:00 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_int(char	*s)
{
	int	at_least_one_int;
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	at_least_one_int = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		at_least_one_int = 1;
		i++;
	}
	return (at_least_one_int);
}

int	exit_(int argc, char **argv, char ***env)
{
	unsigned char	return_value;
	int				error_flag;

	(void)env;
	printf("exit\n");
	if (argc == 1)
		return (g_exit_status);
	error_flag = 0;
	return_value = ft_atol(argv[1], &error_flag);
	if (error_flag == 1 || !is_int(argv[1]))
	{
		ft_fprintf(2,
			"minishell: exit: %s: numeric argument required\n", argv[1]);
		return (2);
	}
	if (argc > 2)
	{
		ft_fprintf(2, "minishell: exit: too many arguments\n");
		return (-1);
	}
	return (return_value);
}
