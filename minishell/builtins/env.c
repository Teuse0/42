/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:45:50 by tguerin           #+#    #+#             */
/*   Updated: 2022/12/06 17:34:51 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	env(int argc, char **argv, char ***env)
{
	int		i;

	(void)argv;
	if (argc > 1)
	{
		ft_fprintf(2, "env: too many arguments\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while ((*env)[i])
	{
		if (ft_strchr((*env)[i], '='))
			ft_fprintf(1, "%s\n", (*env)[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
