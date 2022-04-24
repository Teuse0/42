/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:46:54 by broy              #+#    #+#             */
/*   Updated: 2022/02/20 11:01:38 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	unsigned int	n;
	char	*dest;
	char	*src;
	char	*ptrdest;

	src = "connard de virus";
	printf("%s\n", src);
	n = 16;
	ptrdest = &*dest;
	ptrdest = ft_strncpy(dest, src, n);
	printf("%s\n", ptrdest);
}
