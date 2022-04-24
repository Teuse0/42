/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:57:09 by broy              #+#    #+#             */
/*   Updated: 2022/02/21 16:22:39 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (src[i])
		i++;
	while (src[j] && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

int	main(void)
{
	char	dest[100];
	char	src[] = "Coronavirus connard de virus";
	unsigned int	size;

	size = 5;
	printf("%d\n", size);
	printf("%d\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return (0);
}
