/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:45:24 by broy              #+#    #+#             */
/*   Updated: 2022/04/14 10:45:40 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uintsize(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;
	int		j;

	i = ft_uintsize(n);
	j = i;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	while (n > 0)
	{
		i--;
		str[i] = n % 10 + 48;
		n = n / 10;
	}
	str[j] = 0;
	return (str);
}

int	ft_print_uint(unsigned int n)
{
	int		i;
	char	*num;

	i = 0;
	if (n == 0)
		i += ft_printchar(48);
	num = ft_uitoa(n);
	i += ft_printstr(num);
	free(num);
	return (i);
}
