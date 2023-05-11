/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:32:08 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:32:09 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << this->type << " constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
  	  std::cout << "Animal " << this->type << " constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal makeSound called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return this->type;
}
