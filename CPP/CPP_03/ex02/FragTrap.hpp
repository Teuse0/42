/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:53:20 by broy              #+#    #+#             */
/*   Updated: 2023/03/16 20:53:22 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &);
	FragTrap &operator=(const FragTrap& rhs);

	void	highFive(void);
};

#endif
