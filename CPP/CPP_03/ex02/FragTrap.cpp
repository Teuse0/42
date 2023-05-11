/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:53:13 by broy              #+#    #+#             */
/*   Updated: 2023/03/16 20:53:14 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "| FragTrap | - " << this->name << " constructed." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "| FragTrap | - " << this->name << " destructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs)
{
	*this = rhs;
	std::cout << "| FragTrap | - copy constructor called" << std::endl;
  	return ;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

void	FragTrap::highFive(void)
{
	if (hitPoints <= 0)
	{
		std::cout << "FragTrap " << name << " is already dead :( !" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "| FragTrap | - " << this->name << " is out of energy." << std::endl;
		return;
	}
	std::cout << "| FragTrap | - " << this->name << " high fives ?" << std::endl;
	this->energyPoints -= 1;
}
