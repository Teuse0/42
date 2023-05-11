/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:25 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:26 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*inventory[4];

public:
	Character(std::string const &name);
	Character(Character const &src);
	~Character();
	Character& operator=(Character const &rhs);

	std::string const&	getName() const;
	void			equip(AMateria* m);
	void			unequip(int idx);
	void			use(int idx, ICharacter& target);
};

#endif
