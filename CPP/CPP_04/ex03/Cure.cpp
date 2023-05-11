/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:25 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:26 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "* Cure: materia is created *" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria("cure")
{
	*this = src;
	std::cout << "* Cure: materia is copied *" << std::endl;
}

Cure&   Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
 	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "* Cure: cure is destroyed *" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
