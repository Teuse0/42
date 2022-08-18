/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:52:31 by broy              #+#    #+#             */
/*   Updated: 2022/07/24 21:42:32 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(t_all *all)
{
	ft_putstr_fd("Error\n", 2);
	if (all->check == 1)
		ft_free_array(all->input);
	exit(1);
}

void	ft_free_all(t_all *all, int *num, int *index, char **bin)
{
	int	i;

	free(index);
	index = NULL;
	free(num);
	num = NULL;
	ft_ps_lstclear(&all->a);
	ft_ps_lstclear(&all->b);
	i = 0;
	while (i < all->len)
	{
		free(bin[i]);
		i++;
	}
	free(bin);
}

void	ft_ps_lstclear(t_stack **lst)
{
	t_stack	*aux;
	t_stack	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}
