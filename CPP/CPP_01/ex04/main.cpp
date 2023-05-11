/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:22:04 by broy              #+#    #+#             */
/*   Updated: 2023/02/13 16:22:05 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error : ./Replace <filename> <find> <replace>" << std::endl;
		return (1);
	}
	else if (!av[2][0])
	{
		std::cerr << "Error : You can't replace an empty string" << std::endl;
	}
	else
	{
		Replace   sed2(av[1]);
		sed2.replace(av[2], av[3]);
	}
	return (0);
}
