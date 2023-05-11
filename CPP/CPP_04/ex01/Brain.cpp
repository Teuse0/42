/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:31:36 by broy              #+#    #+#             */
/*   Updated: 2023/03/17 17:31:37 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brain assigment operator called." << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	}
	return (*this);
}
