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
}

Cat::~Cat(void)
{
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
	}
	return (*this);
}

void    Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}
