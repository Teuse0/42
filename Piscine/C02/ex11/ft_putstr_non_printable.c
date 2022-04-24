/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:25:16 by broy              #+#    #+#             */
/*   Updated: 2022/02/21 18:23:21 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_prt_hex(char c)
{
	int		i;
	char	hex1;
	char	hex2;

	ft_putchar('\\');
	if (c < 0)
	{
		i = (-128 - (c)) * -1 + 128;
		hex1 = i / 16;
		hex2 = i % 16;
	}
	else
	{
		hex1 = c / 16;
		hex2 = c % 16;
	}
	if (hex1 < 10)
		ft_putchar(hex1 + 48);
	else
		ft_putchar(hex1 + 87);
	if (hex2 < 10)
		ft_putchar(hex2 + 48);
	else
		ft_putchar(hex2 + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_prt_hex(str[i]);
		i++;
	}
}

int	main(void)
{
	char	*str;

	str = ;
	ft_putstr_non_printable(str);
}
