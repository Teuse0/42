/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:32:20 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:32:21 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
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

Cat::~Cat(void)
{
	delete  this->brain;
	std::cout << this->type << " destructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

void    Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}
