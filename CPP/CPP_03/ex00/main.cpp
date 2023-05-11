/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:27 by broy              #+#    #+#             */
/*   Updated: 2023/03/10 14:52:27 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("Pikachu");
	clap.attack("Snorlax");
	clap.takeDamage(5);
	clap.beRepaired(10);
	clap.attack("Snorlax");
	clap.takeDamage(15);
	clap.attack("Thunder");
	clap.beRepaired(5);
	
	ClapTrap clap2("Charizard");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	clap2.attack("Snorlax");
	

	return (0);
}
