/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:27 by broy              #+#    #+#             */
/*   Updated: 2023/03/10 14:52:27 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{	
	ScavTrap ash("Pikachu");
	ScavTrap ash2(ash);
	ScavTrap ash3("Charizard");

	ash.attack("Snorlax");
	ash.takeDamage(10);
	ash.beRepaired(10);
	ash.guardGate();
	ash.takeDamage(100);
	ash.guardGate();
	ash3.attack("Snorlax");
	ash2.guardGate();

	return (0);
}
