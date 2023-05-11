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
	Fixed(void);
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &value);
	Fixed &operator=(const Fixed &value);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;

	bool	operator>(const Fixed &value) const ;
	bool	operator<(const Fixed &value) const ;
	bool	operator>=(const Fixed &value) const ;
	bool	operator<=(const Fixed &value) const ;
	bool	operator==(const Fixed &value) const ;
	bool	operator!=(const Fixed &value) const ;

	Fixed	operator+(const Fixed &value) const ;
	Fixed	operator-(const Fixed &value) const ;
	Fixed	operator*(const Fixed &value) const ;
	Fixed	operator/(const Fixed &value) const ;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static		Fixed& min(Fixed &a, Fixed &b);
	static const	Fixed& min(const Fixed &a, const Fixed &b);
	static		Fixed& max(Fixed &a, Fixed &b);
	static const	Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
