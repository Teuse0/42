/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:22:33 by broy              #+#    #+#             */
/*   Updated: 2023/02/13 16:22:34 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::string input = av[1];
	Harl	harl;
	harl.complain(input);
	return (0);
}
