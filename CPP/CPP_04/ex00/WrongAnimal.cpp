/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:32:03 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:32:03 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Wrong Animal")
{
	std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
  	  std::cout << "Wrong Animal " << this->type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "Wrong Animal assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Animal makeSound called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return this->type;
}
