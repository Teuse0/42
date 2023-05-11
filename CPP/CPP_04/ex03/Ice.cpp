/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:25 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:26 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "* Ice: materia is created *" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria("ice")
{
	*this = src;
	std::cout << "* Ice: materia is copied *" << std::endl;
}

Ice&   Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "* Ice: ice is destroyed *" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
