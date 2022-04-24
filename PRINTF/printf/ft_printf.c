/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:30:58 by broy              #+#    #+#             */
/*   Updated: 2022/04/13 19:51:58 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_type(const char c, va_list ptr)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(ptr, int));
	else if (c == 's')
		count += ft_printstr(va_arg(ptr, char *));
	else if (c == 'p')
		count += ft_print_adress(va_arg(ptr, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += ft_printnbr(va_arg(ptr, int));
	else if (c == 'u')
		count += ft_print_uint(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_printhexa(va_arg(ptr, unsigned int), c);
	else if (c == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_type(str[i + 1], ptr);
			i++;
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
