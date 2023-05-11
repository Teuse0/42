/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:24:05 by broy              #+#    #+#             */
/*   Updated: 2023/02/11 17:24:06 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	std::string name;

	std::cout << "Calling randomChump" << std::endl;
	std::cout << "Creating zombie on the stack" << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;
	randomChump( name );

	std::cout << "Creating zombie on the heap" << std::endl;
	std::cout << "Zombie name: " << std::flush;
	std::cin >> name;

	Zombie *zombi2 = newZombie(name);
	zombi2->announce();
	delete zombi2;

	return 0;
}
