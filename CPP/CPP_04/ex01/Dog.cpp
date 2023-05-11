/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:32:14 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:32:15 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << this->type << " constructor called" << std::endl;
	try
	{
		this->brain = new Brain();
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
	}
}

Dog::~Dog(void)
{
	delete  this->brain;
	std::cout << this->type << " destructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

void    Dog::makeSound(void) const
{
	std::cout << "Wouf !" << std::endl;
}
