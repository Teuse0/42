/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:35:50 by broy              #+#    #+#             */
/*   Updated: 2022/05/16 13:35:51 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "server.h"

int	g_size;	

void	ft_end(int *i, int *j, char **str)
{
	if (g_size != 0)
	{
		(*str)[*i] = 0;
		write(1, *str, g_size);
		free(*str);
		*str = NULL;
	}
	*i = 0;
	g_size = 0;
	*j = 0;
}

void	ft_bit_to_str(int *i, int *n, int *bit, char **str)
{
	(*str)[*i] = *bit;
	*i = *i + 1;
	*n = 0;
	*bit = 0;
}

void	ft_get_size(int *j, int sig)
{
	if (sig == SIGUSR1)
		g_size += 1 << (31 - *j);
	*j = *j + 1;
}

void	handler(int sig)
{
	static int	n;
	static int	bit;
	static int	i;
	static char	*str;
	static int	j;

	if (j <= 31)
		return (ft_get_size(&j, sig));
	if (g_size == 0)
		return (ft_end(&i, &j, &str));
	if (str == NULL)
		str = malloc(g_size + 1);
	if (sig == SIGUSR1)
		bit += 1 << (7 - n);
	n++;
	if (n == 8)
		ft_bit_to_str(&i, &n, &bit, &str);
	if (i == g_size)
		ft_end(&i, &j, &str);
}

int	main(void)
{
	write(1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		continue ;
	return (0);
}
