/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:41:08 by argomez           #+#    #+#             */
/*   Updated: 2022/02/19 11:00:52 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_line_start(int line, int column, int count_column)
{
	ft_putchar('/');
	count_column = 1;
	while (count_column <= column - 2)
	{
		ft_putchar('*');
		count_column++;
	}
	if (column > 1)
	{
		ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	print_line_middle(int line, int column, int count_column)
{
	ft_putchar('*');
	line = 1;
	while (count_column <= column - 2)
	{
		ft_putchar(' ');
		count_column++;
	}
	if (column > 1)
	{
		ft_putchar('*');
	}
	ft_putchar('\n');
}

void	print_line_end(int line, int column, int count_column)
{
	ft_putchar('\\');
	while (count_column <= column - 2)
	{
		ft_putchar('*');
		count_column++;
	}
	if (column > 1)
	{
		ft_putchar('/');
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
	rush(0,10);
	ft_putchar('.');
	ft_putchar('\n');
	rush(10,0);
	ft_putchar('.');
	ft_putchar('\n');
	rush(1,1);
	ft_putchar('.');
	ft_putchar('\n');
	rush(10,1);
	ft_putchar('.');
	ft_putchar('\n');
	rush(1,10);
	ft_putchar('.');
	ft_putchar('\n');
	rush(10,10);
	ft_putchar('.');
	ft_putchar('\n');
	rush(-5,10);
	ft_putchar('.');
	ft_putchar('\n');
	rush(10,-5);
	rush(100,54);
}
