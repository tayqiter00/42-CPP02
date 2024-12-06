/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:18:34 by qtay              #+#    #+#             */
/*   Updated: 2024/12/05 22:06:08 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * We're asked to fix the fractional bits as 8. This leaves 24 bits for the
 * non-fractional part.
 */
const int	Fixed::_fractionalBits = 8;

/**
 * Can also do Fixed::Fixed(): _value(0)
 */
Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	_value = obj._value;
	std::cout << "Copy constructor called\n";

}

Fixed	&Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		this->_value = obj.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}
