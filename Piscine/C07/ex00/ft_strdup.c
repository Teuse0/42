/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:30:36 by broy              #+#    #+#             */
/*   Updated: 2022/03/02 11:36:49 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char	*src)
{
	int		i;
	char	*pt;

	i = 0;
	while (src[i])
		i++;
	pt = malloc(sizeof(char) * i);
	if (pt == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		pt[i] = src[i];
		i++;
	}
	return (pt);
}
