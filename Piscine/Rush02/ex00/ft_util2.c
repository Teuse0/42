/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:27:36 by rgallois          #+#    #+#             */
/*   Updated: 2022/03/06 18:46:25 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	ft_strlen(char *str)
{
	int	char_count;

	char_count = 0;
	while (str[char_count] != '\0')
	{
		char_count++;
	}
	return (char_count);
}

void	ft_free_dict(t_dict *dict)
{
	int	index;

	index = 0;
	while (ft_strcmp(dict[index].value_num, "null") != 0)
	{
		free(dict[index].value_num);
		free(dict[index].value_alpha);
		index++;
	}
	free(dict);
}
