/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:00:29 by broy              #+#    #+#             */
/*   Updated: 2023/02/08 18:00:30 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	this->amount = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::show_startup(void)
{
	std::cout << "# PHONEBOOK" << std::endl;
	std::cout << "# Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
}

void Phonebook::add_contact(void)
{
	if (this->contacts[this->amount % 8].set_informations((this->amount) % 8))
		this->amount++;
}

void Phonebook::show_search_header(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; (i < this->amount) && (i < 8); i++)
		this->contacts[i % 8].display_header();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void Phonebook::search_contact(void)
{
	int	index;

	if (this->amount == 0)
		std::cout << "# Add a contact before searching !" << std::endl;
	else
	{
		this->show_search_header();
		std::cout << "# Enter Index to display Informations or 0 to Exit\n~";
		while (!(std::cin >> index) || (index < 0 || index >= this->amount || index >= 8))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "# Invalid Index\n~";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index >= 0)
			this->contacts[index].display();
	}
}
