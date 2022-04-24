/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:09:10 by broy              #+#    #+#             */
/*   Updated: 2022/02/21 15:47:51 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src [j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

int	main(void)
{
	char	dest[100] = "Coronavirus, ";
	char	*src;
	
	src = "connard de virus";
    printf("%s\n", ft_strcat(dest, src));
//	printf("%s\n", strcat(dest, src));
}
