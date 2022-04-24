/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:04:03 by broy              #+#    #+#             */
/*   Updated: 2022/03/02 12:23:32 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int	*ft_range(int min, int max);

int	main(int argc, char *argv[])
{
	int i = 0;
	int	*tab;

	if (argc != 3)
		return (1);
	printf("min %s, max %s, tab ", argv[1], argv[2]);
	tab = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (i < (atoi(argv[2]) - atoi(argv[1])))
	{
		printf("%d", tab[i]);
		i++;
	}
	return (0);
}
