/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex06.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:37:38 by broy              #+#    #+#             */
/*   Updated: 2022/02/25 09:42:36 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_is_prime(int nb);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("%d\n", ft_is_prime(atoi(argv[1])));
}
