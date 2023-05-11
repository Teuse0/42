/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:31:36 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:31:37 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(std::string type);
	virtual ~Animal( void );
	Animal(const Animal& src);
	Animal& operator=(const Animal& rhs);

	virtual void	makeSound(void) const;
	std::string	getType(void) const; 
};

#endif
