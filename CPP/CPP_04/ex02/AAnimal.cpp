/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:32:08 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:32:09 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type( "AAnimal" )
{
	std::cout << this->_type << " constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type( type )
{
	std::cout << "AAnimal " << this->_type << " constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return (*this);
}

void AAnimal::makeSound(void) const
{
	std::cout << "AAnimal makeSound called" << std::endl;
}

std::string    AAnimal::getType(void) const
{
	return this->type;
}
