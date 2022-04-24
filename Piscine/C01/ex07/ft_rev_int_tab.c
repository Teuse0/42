/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:36:06 by broy              #+#    #+#             */
/*   Updated: 2022/02/18 18:02:34 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}		
}

int	main(void)
{
	int	*tab;
	int	size;
	int	i;
	int	tab2[6];

	size = 6;
	i = 0;
	tab = &tab2[i];
	tab2[0] = 1;
	tab2[1] = 2;
	tab2[2] = 3;
	tab2[3] = 4;
	tab2[4] = 5;
	tab2[5] = 6;
	ft_rev_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
