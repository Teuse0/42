/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:23:12 by broy              #+#    #+#             */
/*   Updated: 2022/03/07 10:08:17 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	j = 0;
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = min;
	while (i < max)
	{
		(*range)[j] = i;
		i++;
		j++;
	}
	return ((max - min));
}
