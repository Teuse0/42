/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:24:53 by broy              #+#    #+#             */
/*   Updated: 2023/02/24 17:24:54 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
	private:
	std::string _inFile;
	std::string _outFile;

	public:
	Replace(std::string filename);
	~Replace();

	void	replace(std::string s1, std::string s2);
};

#endif
