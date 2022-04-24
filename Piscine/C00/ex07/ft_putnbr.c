/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:55:53 by broy              #+#    #+#             */
/*   Updated: 2022/02/28 10:54:38 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	nbc[10];
	long	nbn;
	int		i;

	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		ft_putchar('-');
		nbn = nb;
		nbn = -nbn;
	}
	else
		nbn = nb;
	i = 0;
	while (nbn > 0)
	{
		nbc[i] = nbn % 10 + 48;
		nbn = nbn / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbc[i]);
}

int	main(void)
{
	ft_putnbr(-2147483648);
}
