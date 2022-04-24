/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:32:29 by broy              #+#    #+#             */
/*   Updated: 2022/02/19 12:34:12 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}
void	rush(int	column, int	line)
{
	int	i;
	int	j;
	
	i = 1;
	j = 1;
	if (column > 0)
	{
		if (line > 0)
		{
			ft_putchar('/');
			while (i <= column - 2)
			{
				ft_putchar('*');
				i++;
			}
			if (column > 1)
				ft_putchar('\\');
			ft_putchar('\n');
			j++;
		}
		while (line > 1 && j <= line - 1)
		{
			i = 1;
			ft_putchar('*');
			//line = 1;
			while (i <= column - 2)
			{
				ft_putchar(' ');
				i++;
			}
			if (column > 1)
				ft_putchar('*');
			ft_putchar('\n');
			j++;
		}
		if (j == line)
		{
			i = 1;
			ft_putchar('\\');
			while (i <= column - 2)
			{
				ft_putchar('*');
				i++;
			}
			if (column > 1)
				ft_putchar('/');
			ft_putchar('\n');
		}
	}
}

int	main(void)
{
	rush(1,8);
}
