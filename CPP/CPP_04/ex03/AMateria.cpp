/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:25 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:26 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("")
{
	std::cout << "* AMateria: materia is created *" << std::endl;
}

AMateria::AMateria(std::string const & type)  : type(type)
{
	std::cout << "AMateria " << this->type << " created" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria " << this->type << " destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

AMateria* AMateria::clone() const
{
	return ((AMateria*)this);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}
