/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:24:23 by broy              #+#    #+#             */
/*   Updated: 2023/02/24 17:24:24 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename) : _inFile(filename)
{
	this->_outFile = this->_inFile + ".replace";
}

Replace::~Replace (void)
{
}

void	Replace::replace(std::string find, std::string replace)
{
	std::ifstream	ifs(this->_inFile);
	if (ifs.is_open())
	{
		std::string file_content;
		if (std::getline(ifs, file_content, '\0'))
		{
			std::ofstream	ofs(this->_outFile);
			size_t		i = file_content.find(find);
			while (i != std::string::npos)
			{
				file_content.erase(i, find.length());
				file_content.insert(i, replace);
				i = file_content.find(find);
			}
			ofs << file_content;
			ofs.close();
		}
		else
		{
			std::cerr << "Empty file" << std::endl;
		}
		ifs.close();
	}
	else
	{
		std::cerr << "Error oppening file" << std::endl;
		exit(EXIT_FAILURE);
	}
}
