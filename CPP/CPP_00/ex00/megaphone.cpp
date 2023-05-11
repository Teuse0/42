/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:14:19 by broy              #+#    #+#             */
/*   Updated: 2023/01/06 15:14:20 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int	main(int ac, char *av[])
{
	int	i = 1;
	size_t	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			j = 0;
			std::string str(av[i]);
			while (j < str.length())
			{
				std::cout << (char)std::toupper(str[j]);
				j++;
			}
			i++;	
		}
		std::cout << std::endl;
	}
	return (0);
}
