/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:21:12 by broy              #+#    #+#             */
/*   Updated: 2023/02/13 16:21:18 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int	i = 0;
	Zombie *zombie = new Zombie[N];
	while (i < N)
	{
		zombie[i].setName(name);
		i++;
	}
	return zombie;
}
