/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:56:48 by broy              #+#    #+#             */
/*   Updated: 2022/02/27 17:28:59 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_corner(char *str, int a, int b);

void	ft_remove_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[j - 1] && str[j]) || j == 0)
	{
		str[i] = str[j];
		i++;
		j = j + 2;
	}
	str[i] = 0;
}

int	ft_check_line2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '3' && (i <= 6 || (i <= 22 && i >= 16)))
		{
			if (str[i] == '3' && str[i + 8] == '3')
				return (1);
		}
		i++;
	}
	return (0);
}
int	ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '4' && (i <= 6 || (i <= 22 && i >= 16)))
		{
			if (!(str[i] == '4' && str[i + 8] == '1'))
				return (1);
		}
		if (str[i] == '4' && (i >= 25 || (i <= 14 && i >= 8)))
		{
			if (!(str[i] == '4' && str[i - 8] == '1'))
				return (1);
		}
		if (ft_check_line2(str))
			return (1);
		i++;
	}
	
		if (ft_corner(str, 0, 16))
			return (1);
		if (ft_corner(str, 6, 24))
			return (1);
		if (ft_corner(str, 14, 30))
			return (1);
		if (ft_corner(str, 8, 22))
			return (1);

	return (0);
}

int	ft_param_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
			if (!(str[i] <= '4' && str[i] >= '1'))
				return (1);
		i++;
	}
	if (str[31] != 0)
		return (1);
	if (ft_check_line(str))
		return (1);
	ft_remove_space(str);
	return (0);
}
