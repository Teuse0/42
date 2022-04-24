/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:08:54 by broy              #+#    #+#             */
/*   Updated: 2022/02/24 11:44:39 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destsize;
	unsigned int	i;
	int				srcsize;

	srcsize = 0;
	destsize = 0;
	while (src[srcsize])
		srcsize++;
	if (size == 0)
		return (srcsize);
	while (dest[destsize])
		destsize++;
	if (size <= destsize)
		return (size + srcsize);
	i = 0;
	while (src[i])
	{
		dest[destsize + i] = src[i];
		i++;
	}
	dest[destsize + i] = 0;
	return (srcsize + destsize);
}

int	main(void)
{
	char	dest[100] = "1234";
	char	src[100] = "ABCD";

	printf("%d\n", ft_strlcat(dest, src, 0));
	printf("%s\n", dest);
}
