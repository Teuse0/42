/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:24:42 by broy              #+#    #+#             */
/*   Updated: 2022/02/18 14:38:19 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;
	c = *a;
	*a = *a / *b;
	*b = c % *b;
}

int	main(void)
{
	int *a;
	int	*b;
	int num1;
	int num2;

	num1 = 25;
	num2 = 2;
	a = &num1;
	b = &num2;
	ft_ultimate_div_mod(a, b);	
	printf("%d, %d", *a, *b);
}
