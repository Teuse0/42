/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:37:34 by broy              #+#    #+#             */
/*   Updated: 2023/02/19 15:37:35 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack( void )// const
{
    if (this->_weapon.getType() != "")
    {
        std::cout << _name << " attacks with their " << this->_weapon.getType() << std::endl;
    }
    else
    {
        std::cout << _name << " doesn't have weapon." << std::endl;
    }
}
