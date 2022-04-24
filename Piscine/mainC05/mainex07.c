/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex07.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:11:15 by broy              #+#    #+#             */
/*   Updated: 2022/02/26 19:45:12 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf("%d\n", ft_find_next_prime(atoi(argv[1])));
}

