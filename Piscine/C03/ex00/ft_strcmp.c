/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:36:27 by broy              #+#    #+#             */
/*   Updated: 2022/02/24 19:02:26 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] != 0)
		return (-s2[i]);
	else
		return (0);
}
int	main()
{
	int	i;
	char	*s1;
	char	*s2;

	s1 = "coucou";
	s2 = "coucouger";
	i = ft_strcmp(s1, s2);
	printf("%d\n", i);
	printf("%d", strcmp(s1, s2));
}
