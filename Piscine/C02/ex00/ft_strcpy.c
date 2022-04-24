/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:02:00 by broy              #+#    #+#             */
/*   Updated: 2022/02/20 10:39:22 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	*dest;
	char	*src;
	char	*ptrdest;

	src = "connard de virus";
	ptrdest = &*dest;
	printf("%s\n", src);
	ptrdest = ft_strcpy(dest, src);
	printf("%s\n", ptrdest);
}
