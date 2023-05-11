/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:31:43 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:31:44 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	virtual ~WrongAnimal(void);
	WrongAnimal(const WrongAnimal& src);
	WrongAnimal& operator=(const WrongAnimal& rhs);

	virtual void	makeSound(void) const;
	std::string	getType(void) const; 
};

#endif
