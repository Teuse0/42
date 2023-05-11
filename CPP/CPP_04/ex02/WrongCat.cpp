/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:31:57 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:31:58 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat")
{
	std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->type << " destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "Wrong Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void    WrongCat::makeSound(void) const
{
	std::cout << "NOPE !" << std::endl;
}
