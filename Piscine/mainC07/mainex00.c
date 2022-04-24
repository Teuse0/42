/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:31:26 by broy              #+#    #+#             */
/*   Updated: 2022/03/02 11:31:23 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf("%s\n", strdup(argv[1]));
	printf("%s\n", ft_strdup(argv[1]));
	return (0);
}
