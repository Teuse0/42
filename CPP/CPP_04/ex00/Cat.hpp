/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:30:47 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:30:48 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
	Cat(void);
	~Cat(void);
	Cat(const Cat& src);
	Cat& operator=(const Cat& rhs);

	void	makeSound(void) const;
};

#endif
