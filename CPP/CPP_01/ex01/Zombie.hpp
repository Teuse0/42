/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:29 by broy              #+#    #+#             */
/*   Updated: 2023/02/13 16:02:29 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    
private:
	std::string _name;

public:
	Zombie();
	~Zombie();
	void	announce(void);
	Zombie* newZombie(std::string name);
	void 	setName(std::string name);

};

Zombie*	zombieHorde(int N, std::string name);

#endif
