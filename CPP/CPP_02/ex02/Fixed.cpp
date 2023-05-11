/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:33:36 by broy              #+#    #+#             */
/*   Updated: 2023/02/24 18:33:37 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _FixedValue(0)
{
}

Fixed::Fixed(const int n) : _FixedValue(n << _Bits)
{
}

Fixed::Fixed(const float n) : _FixedValue(std::roundf(n * (1 << _Bits)))
{
}

Fixed::Fixed(const Fixed &rhs)
{
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed &value)
{
	if (this != &value)
		this->_FixedValue = value.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_FixedValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_FixedValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _Bits));
}

int	Fixed::toInt(void) const
{
	return (this->_FixedValue >> _Bits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

bool	Fixed::operator>(const Fixed &value) const
{
	return (this->getRawBits() > value.getRawBits());
}

bool	Fixed::operator<(const Fixed &value) const 
{
	return (this->getRawBits() < value.getRawBits());
}

bool	Fixed::operator>=(const Fixed &value) const
{
	return (this->getRawBits() >= value.getRawBits());
}

bool	Fixed::operator<=(const Fixed &value) const
{
	return (this->getRawBits() <= value.getRawBits());
}

bool	Fixed::operator==(const Fixed &value) const
{
	return (this->getRawBits() == value.getRawBits());
}

bool	Fixed::operator!=(const Fixed &value) const
{
	return (this->getRawBits() != value.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &value) const
{
	return (Fixed(this->toFloat() + value.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &value) const
{
	return (Fixed(this->toFloat() - value.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &value) const
{
	return (Fixed(this->toFloat() * value.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &value) const
{
	return (Fixed(this->toFloat() / value.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	++this->_FixedValue;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	tmp._FixedValue = this->_FixedValue++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	--this->_FixedValue;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	tmp._FixedValue = this->_FixedValue--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const	Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
