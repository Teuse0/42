/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:40 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:41 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
	Dog(void);
	~Dog(void);
	Dog(const Dog& src);
	Dog& operator=(const Dog& rhs);

	void	makeSound(void) const;
};

#endif
