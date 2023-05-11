/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:18 by broy              #+#    #+#             */
/*   Updated: 2023/02/13 16:02:19 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 115

int main(int ac, char **av)
{
	int	i = 0;

	if (ac > 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}
	if (ac == 1)
	{
		Zombie *zombie = zombieHorde(N, "zombi");
		while (i < N)
		{
			zombie[i].announce();
			i++;
   		}
   		delete [] zombie;
	}
	else 
	{
		Zombie *zombie = zombieHorde(N, av[1]);
		while (i < N)
		{
			zombie[i].announce();
			i++;
   		}
   		delete [] zombie;
	}
	return 0;
}
