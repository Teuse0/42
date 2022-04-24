/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:59:31 by broy              #+#    #+#             */
/*   Updated: 2022/02/19 15:10:22 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	print_line_start(int line, int column, int count_column)
{
	ft_putchar('A');
	count_column = 1;
	while (count_column <= column - 2)
	{
		ft_putchar('B');
		count_column++;
	}
	if (column > 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	print_line_middle(int line, int column, int count_column)
{
	ft_putchar('B');
	line = 1;
	while (count_column <= column - 2)
	{
		ft_putchar(' ');
		count_column++;
	}
	if (column > 1)
	{
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	print_line_end(int line, int column, int count_column)
{
	ft_putchar('C');
	while (count_column <= column - 2)
	{
		ft_putchar('B');
		count_column++;
	}
	if (column > 1)
	{
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	count_line;
	int	count_column;

	count_line = 1;
	count_column = 1;
	if (x > 0)
	{
		if (y > 0)
		{
			print_line_start(y, x, count_column);
			count_line ++;
		}
		while (1 < y && count_line <= y - 1)
		{
			print_line_middle(y, x, count_column);
			count_line++;
		}
		if (count_line == y)
		{
			print_line_end(y, x, count_column);
		}
	}
}

int	main(void)
{
	rush(5,3);
}
