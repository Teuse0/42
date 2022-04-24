/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:07:20 by broy              #+#    #+#             */
/*   Updated: 2022/04/14 16:07:37 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	ft_puthex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar_fd(n + 48, 1);
		}
		else
		{
			if (c == 'x')
				ft_putchar_fd(n - 10 + 97, 1);
			if (c == 'X')
				ft_putchar_fd(n - 10 + 65, 1);
		}
	}
}

int	ft_printhexa(unsigned int n, const char c)
{
	if (n == 0)
		return (ft_printchar(48));
	ft_puthex(n, c);
	return (ft_hexlen(n));
}
