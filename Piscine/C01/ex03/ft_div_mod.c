/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:57:01 by broy              #+#    #+#             */
/*   Updated: 2022/02/19 17:44:16 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	a = 46;
	int	b = 20;
	int resultat;
	int reste;
	int	*div;
	int	*mod;

	div = &resultat;
	mod = &reste;
	ft_div_mod(a, b, div, mod);
	printf("%d, %d, %d, %d", a, b, *div, *mod);	
}
