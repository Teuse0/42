/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:00:16 by broy              #+#    #+#             */
/*   Updated: 2023/02/08 18:00:18 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::fields_name[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = FirstName; i <= Secret; i++)
		this->informations[i] = std::string();
}

Contact::~Contact()
{
}

bool Contact::set_informations(int index)
{
	this->index = index;
	for (int i = FirstName; i <= Secret; i++)
	{
		std::cout << "# " << Contact::fields_name[i] << ":\n+";
		std::getline(std::cin, this->informations[i]);
	}
	size_t totalLength = 0;
	for (int i = FirstName; i <= Secret; i++)
		totalLength += this->informations[i].length();
	if (totalLength == 0)
	{
		std::cout << "# Empty contact not added !" << std::endl;
		return (false);
	}
	std::cout << "# Contact added !" << std::endl;
	return (true);
}

void Contact::display_header()
{
	std::cout << "|" << std::setw(10) << this->index;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->informations[i].length() > 10)
			std::cout << this->informations[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->informations[i];
	}
	std::cout << "|" << std::endl;
}

void Contact::display(void)
{
	std::cout << "# Contact [" << this->index << "]" << std::endl;
	for (int i = FirstName; i <= Secret; i++)
	{
		std::cout << Contact::fields_name[i] << ": ";
		std::cout << this->informations[i] << std::endl;
	}
}
