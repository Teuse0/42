/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:37:47 by broy              #+#    #+#             */
/*   Updated: 2023/02/19 15:37:48 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

void	HumanB::attack( void )// const
{
    if (this->_weapon != NULL && this->_weapon->getType() != "")
    {
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << _name << " doesn't have a weapon." << std::endl;
    }
}
