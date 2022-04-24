/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:37:05 by broy              #+#    #+#             */
/*   Updated: 2022/04/16 19:38:54 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("TEST CHAR\n\n");
	printf("Retour printf : %d\n\n", printf("%c\n", 'r'));
	printf("Retour ft_printf : %d\n\n", ft_printf("%c\n", 'r'));
	
	char	*g = "qwertyuiop";
	printf("TEST STRING\n\n");
	printf("Retour printf : %d\n\n", printf("%s\n", g));
	printf("Retour ft_printf : %d\n\n", ft_printf("%s\n", g));

	int	i = 2147483647;
	printf("TEST INT (d)\n\n");
	printf("Retour printf : %d\n\n", printf("%d\n", i));
	printf("Retour ft_printf : %d\n\n", ft_printf("%d\n", i));
	
	printf("TEST INT (i)\n\n");
	printf("Retour printf : %d\n\n", printf("%i\n", i));
	printf("Retour ft_printf : %d\n\n", ft_printf("%i\n", i));
	
	unsigned int 	j = 0;
	printf("TEST UNSIGNED INT\n\n");
	printf("Retour printf : %d\n\n", printf("%u\n", j));
	printf("Retour ft_printf : %d\n\n", ft_printf("%u\n", j));
	
	printf("TEST %%\n\n");
	printf("Retour printf : %d\n\n", ft_printf("%%\n"));
	printf("Retour ft_printf : %d\n\n", ft_printf("%%\n"));
	
	printf("TEST HEXA\n\n");
	printf("Retour printf : %d\n\n", printf("%x %X\n", j, i));
	printf("Retour ft_printf : %d\n\n", ft_printf("%x %X\n", j, i));
	
	printf("TEST ADRESSE\n\n");
	printf("Retour printf : %d\n\n", printf("%p %p %p\n", &i, &j, &g));
	printf("Retour ft_printf : %d\n\n", ft_printf("%p %p %p\n", &i, &j, &g));
	
	printf("TEST GENERAL\n\n");
	printf("Retour printf : %d\n\n", printf("qwerty %d ft %c op %s%i kop %%%u %X\n", i, 'r', g, i, j, i));
	printf("Retour ft_printf : %d\n\n", ft_printf("qwerty %d ft %c op %s%i kop %%%u %X\n", i, 'r', g, i, j, i));
}
