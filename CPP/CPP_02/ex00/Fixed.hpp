/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:33:43 by broy              #+#    #+#             */
/*   Updated: 2023/02/24 18:33:43 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
private:
	int			_FixedValue;
	static const int	_Bits = 8;

public:
	Fixed();
	Fixed(const Fixed &value);
	Fixed &operator=(const Fixed &value);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
