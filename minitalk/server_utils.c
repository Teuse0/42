/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:04:22 by broy              #+#    #+#             */
/*   Updated: 2022/05/16 14:04:23 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "server.h"

void	ft_putchar(char c, int fd)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nbc[10];
	long	nbn;
	int		i;

	if (n == 0)
		ft_putchar('0', fd);
	if (n < 0)
	{
		ft_putchar('-', fd);
		nbn = n;
		nbn = -nbn;
	}
	else
		nbn = n;
	i = 0;
	while (nbn > 0)
	{
		nbc[i] = nbn % 10 + 48;
		nbn = nbn / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbc[i], fd);
}
