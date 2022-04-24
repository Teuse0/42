/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:17:54 by broy              #+#    #+#             */
/*   Updated: 2022/04/14 18:17:57 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress_len(unsigned long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_put_adress(unsigned long n)
{
	if (n >= 16)
	{
		ft_put_adress(n / 16);
		ft_put_adress(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, 1);
		else
			ft_putchar_fd(n - 10 + 97, 1);
	}
}

int	ft_print_adress(unsigned long long n)
{
	int	i;

	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = 0;
	i += ft_printstr("0x");
	ft_put_adress(n);
	i += ft_adress_len(n);
	return (i);
}
