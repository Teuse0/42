/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:25 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:26 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
    std::cout << "Character " << this->name << " created" << std::endl;
}

Character::Character(Character const & src) : name(src.name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = src.inventory[i];
	*this = src;
	std::cout << "Character " << this->name << " created" << std::endl;
}

Character& Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
			this->inventory[i] = rhs.inventory[i];
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character " << this->name << " destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

void    Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			std::cout << "Character " << this->name << " equipped with " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Character " << this->name << " can't equip " << m->getType() << std::endl;
}

void	Character::unequip(int idx)
{
	if (this->inventory[idx])
	{
		delete this->inventory[idx];
		this->inventory[idx] = NULL;
		std::cout << "Character " << this->name << " unequipped" << std::endl;
	}
	else
		std::cout << "Character " << this->name << " can't unequip" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
	{
		this->inventory[idx]->use(target);
		std::cout << "Character " << this->name << " uses " << this->inventory[idx]->getType() << std::endl;
	}
	else
		std::cout << "Character " << this->name << " can't use" << std::endl;
}

std::string const& Character::getName() const
{
	return (this->name);
}
