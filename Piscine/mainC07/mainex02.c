/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:26:50 by broy              #+#    #+#             */
/*   Updated: 2022/03/03 14:09:29 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(int argc, char *argv[])
{
	int 	i = 0;
	int	*range;
	
	if (argc != 3)
		return (1);
	printf("min %s, max %s, taille ", argv[1], argv[2]);
	printf("%d\n", ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2])));
	while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d\n", range[i]);
		i++;
	}
	return (0);
}
