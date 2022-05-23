/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:34:56 by broy              #+#    #+#             */
/*   Updated: 2022/05/16 13:34:58 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "client_bonus.h"

void	ft_char_to_sig(char c, int pid)
{
	int	a;

	a = 7;
	while (a >= 0)
	{
		if (c >> a & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		a--;
	}
}

void	ft_send_size(int size, int pid)
{
	int	a;

	a = 31;
	while (a >= 0)
	{
		if (size >> a & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		a--;
	}	
}

void	ft_received(int sig)
{
	if (sig == SIGUSR1)
		write(1, "\nMessage received successfully ! \n\n", 35);
	exit(EXIT_SUCCESS);
}	

void	ft_send_pid(int pid)
{
	int	a;
	int	c_pid;

	c_pid = getpid();
	a = 31;
	while (a >= 0)
	{
		if (c_pid >> a & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		a--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	if (argc != 3 || !ft_strlen(argv[1]) || !ft_pid_check(argv[1]))
	{
		write(1, "\nError ! Wrong arguments\n\n", 26);
		return (1);
	}
	signal(SIGUSR1, ft_received);
	size = ft_strlen(argv[2]);
	ft_send_size(size, ft_atoi(argv[1]));
	ft_send_pid(ft_atoi(argv[1]));
	if (size == 0)
		kill(ft_atoi(argv[1]), SIGUSR2);
	while (argv[2][i])
	{
		ft_char_to_sig(argv[2][i], atoi(argv[1]));
		i++;
	}
	while (1)
		continue ;
	return (0);
}
