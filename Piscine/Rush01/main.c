/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:50:02 by broy              #+#    #+#             */
/*   Updated: 2022/02/27 16:12:14 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_get_max(char *str);
int	ft_param_valid(char *str);

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_putstr(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 3)
		{
			write (1, "0 ", 2);
			j++;
		}	
		write(1, "0\n", 2);
		j = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error();
		return (1);
	}
	if (ft_param_valid(argv[1]))
	{
		ft_error();
		return (1);
	}
	ft_putstr();
}
