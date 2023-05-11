/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:31:36 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:31:37 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(std::string type);
	virtual ~AAnimal( void );
	AAnimal(const AAnimal& src);
	AAnimal& operator=(const AAnimal& rhs);

	virtual void	makeSound(void) const = 0;
	std::string	getType(void) const; 
};

#endif
