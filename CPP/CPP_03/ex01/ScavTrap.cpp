/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:59:42 by broy              #+#    #+#             */
/*   Updated: 2023/03/10 18:59:43 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "< ScavTrap > - " << this->name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "< ScavTrap > - " << this->name << " destructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs)
{
	*this = rhs;
	std::cout << "< ScavTrap > - copy constructor called" << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

void	ScavTrap::attack(std::string const& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "< ScavTrap > - " << name << " is already dead :( !" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "< ScavTrap > - " << this->name << " is out of energy." << std::endl;
		return ;
	}
	std::cout << "< ScavTrap > - " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage !" << std::endl;
	this->energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	if (hitPoints <= 0)
	{
		std::cout << "< ScavTrap > - " << name << " is already dead :( !" << std::endl;
		return ;
	}
	std::cout << "< ScavTrap > - " << this->name << " is now in Gate keeper mode." << std::endl;
}
