/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:27:24 by broy              #+#    #+#             */
/*   Updated: 2022/02/28 10:58:20 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<stdlib.h>

int	ft_sign(char *str, int	*ptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
	{
		i++;
	}
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	*ptr = i;
	return (sign);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;
	
	i = 0;
	result = 0;
	sign = ft_sign(str, &i);
	//printf("%d\n", sign);
	//printf("i %d\n", i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	//printf("result %d\n", result);
	result *= sign;
	return (result);
}

int	main(void)
{
//	int		a;
	char	*str;

	str = "	 \n \t -+--+++-- ++---2346565";
//	a = ft_atoi(str);
	printf("%d\n", ft_atoi(str));
}
