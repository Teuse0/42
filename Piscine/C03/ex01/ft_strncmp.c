/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:34:55 by broy              #+#    #+#             */
/*   Updated: 2022/02/21 14:56:09 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h> 
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] == 0 || i == n)
		return (0);
	else
		return (-s2[i]);
}
int	main()
{
	int				i;
	char			*s1;
	char			*s2;
	unsigned int	n;

	n = 15;
	s1 = "Connard de virus";
	s2 = "Connard de virus";
	i = ft_strncmp(s1, s2, n);
	printf("%d\n", i);
	i = strncmp(s1, s2, n);
	printf("%d\n", i);
}
