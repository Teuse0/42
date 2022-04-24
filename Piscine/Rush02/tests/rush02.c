/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 10:15:04 by broy              #+#    #+#             */
/*   Updated: 2022/03/05 13:56:31 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
}

int	main(int ac, char **av)
{
	char	*nbr[35];
	int		size;
	int		i;
	int		b;
	int		s;

	if (ac !=2)
		return (1);
	nbr[0] = "zero";
	nbr[1] = "one";
	nbr[2] = "two";
	nbr[3] = "three";
	nbr[4] = "four";
	nbr[5] = "five";
	nbr[6] = "six";
	nbr[7] = "seven";
	nbr[8] = "eight";
	nbr[9] = "nine";
	nbr[10] = "ten";
	nbr[11] = "eleven";
	nbr[12] = "twelve";
	nbr[13] = "thirteen";
	nbr[14] = "fourteen";
	nbr[15] = "fifteen";
	nbr[16] = "sixteen";
	nbr[17] = "seventeen";
	nbr[18] = "eighteen";
	nbr[19] = "nineteen";
	nbr[20] = "twenty";
	nbr[21] = "thirty";
	nbr[22] = "forty";
	nbr[23] = "fifty";
	nbr[24] = "sixty";
	nbr[25] = "seventy";
	nbr[26] = "eighty"; 
	nbr[27] = "ninety";
	nbr[28] = "hundred";
	nbr[29] = "thousand";
	nbr[30] = "million";
	i = 0;
	s = 1;
	size = ft_strlen(av[1]);
	s = size;
	/*while (s > 0)
	{
		b = av[1][i] - 48;
		if (s == 1 && av[1][i - 1] - 48 != 1)
		{
			if (b == 0 && size == 1)
				ft_putstr(nbr[b]);
			else if (b!= 0)
				ft_putstr(nbr[b]);
		}
		if (s == 2 && b == 1)
			ft_putstr(nbr[10 + av[1][i + 1] - 48]);
		if (s == 2 && b > 1)
			ft_putstr(nbr[20 + (b - 2)]);
		if (s == 3 && b != 0)
		{
			ft_putstr(nbr[b]);
			ft_putstr(nbr[28]);
		}
		if (s == 4 && (b != 0 || size > 4))
		{
			if (b != 0 && (av[1][i - 1] - 48 ) != 1)
				ft_putstr(nbr[b]);
			ft_putstr(nbr[29]);
		}
		if (s == 5 && b != 0)
		{
			if (b == 1)
				ft_putstr(nbr[10 + av[1][i + 1] - 48]);
			else if (b > 1)
				ft_putstr(nbr[20 + (b - 2)]);
		}
		if (s == 6 && b != 0)
		{
			ft_putstr(nbr[b]);
			ft_putstr(nbr[28]);
		}
		s--;
		i++;
	}*/
}
