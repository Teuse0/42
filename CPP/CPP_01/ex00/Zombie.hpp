/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:24:15 by broy              #+#    #+#             */
/*   Updated: 2023/02/11 17:24:16 by broy             ###   ########.fr       */
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
	Zombie( std::string name );
	~Zombie();
	void	announce( void );
	Zombie* newZombie( std::string name );
	void 	randomChump( std::string name );

};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif
