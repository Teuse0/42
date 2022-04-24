/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:58:33 by broy              #+#    #+#             */
/*   Updated: 2022/03/02 16:17:03 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c,1);
}

void	ft_putcomb(int i, int j)
{
	char	c1;
	char	c2;

	c1 = (i - (i % 10)) / 10 + 48;
	c2 = i % 10 + 48;
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(' ');
	c1 = (j - (j % 10)) / 10 + 48;
	c2 = j % 10 + '0';
	ft_putchar(c1);
	ft_putchar(c2);
	if (!(i == 98 && j == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != 99)
	{
		while (j <= 99)
		{
			ft_putcomb(i, j);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	main(void)
{
	ft_print_comb2();
}
