/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:06:21 by broy              #+#    #+#             */
/*   Updated: 2022/02/18 19:20:39 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int k;
	int	temp;
	
	i = 0;
	while (i  < size)
	{
		if (tab[i] < tab[i-1])
		{
			j = 0;
			while (tab[j] < tab[i])
				j++;
			temp = tab[i];
			k = i-1;
			while (k >= j)
			{
				tab[k+1] = tab[k];
				k--;
			}
			tab[j] = temp;
		}
		i++;
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
	tab2[0] = 26;
	tab2[1] = 42;
	tab2[2] = 48;
	tab2[3] = 89;
	tab2[4] = 106;
	tab2[5] = 56;
	ft_sort_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
