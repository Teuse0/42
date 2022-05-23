/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:31:27 by broy              #+#    #+#             */
/*   Updated: 2022/05/16 14:31:28 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "client.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

int	ft_pid_check(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < 48 || pid [i] > 57)
			return (0);
		i++;
	}
	return (1);
}
