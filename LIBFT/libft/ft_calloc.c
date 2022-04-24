/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:25:59 by broy              #+#    #+#             */
/*   Updated: 2022/04/02 13:54:13 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*calloc;
	size_t	i;

	i = 0;
	if (size >= 65536 || nmemb >= 65536)
		return (NULL);
	calloc = malloc(size * nmemb);
	if (!calloc)
		return (NULL);
	while (i < nmemb * size)
	{
		calloc[i] = 0;
		i++;
	}
	return ((void *)calloc);
}
