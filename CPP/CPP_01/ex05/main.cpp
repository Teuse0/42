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

int	main(void)
{
	std::string	input;
	Harl		harl;

	std::cout << "Select a level (DEBUG, INFO, WARNING or ERROR) : ";
	std::cin >> input;
	harl.complain(input);
	return(1);
}
