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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap pika("Pikachu");
	pika.attack("Snorlax");
	pika.takeDamage(5);
	pika.beRepaired(10);
	pika.attack("Snorlax");
	pika.highFive();
	pika.takeDamage(15);
	pika.attack("Thunder");
	pika.beRepaired(5);
	
	FragTrap chari("Charizard");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.attack("Snorlax");
	chari.highFive();
	chari.takeDamage(100);
	chari.highFive();
	
	ScavTrap gre("Greninja");

	gre.attack("Snorlax");
	gre.takeDamage(10);
	gre.beRepaired(10);
	gre.guardGate();
	return (0);
}
