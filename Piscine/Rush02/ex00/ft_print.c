/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:30:06 by vnaud             #+#    #+#             */
/*   Updated: 2022/03/06 19:07:58 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_print(t_dict *dict, char *nbr)
{
	int	size;
	int	error;

	size = ft_strlen(nbr);
	if (size > 3)
		return (1);
	if (size % 3 == 0)
		error = ft_pattern_three(dict, nbr);
	else if (size % 3 == 2)
		error = ft_pattern_two(dict, nbr);
	else
		error = ft_pattern_one(dict, nbr);
	if (error == 0)
		return (0);
	return (1);
}
