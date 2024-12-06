/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:18:34 by qtay              #+#    #+#             */
/*   Updated: 2024/11/07 19:19:38 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fractionalBits = 8;

/**
 * Can also do Fixed::Fixed(): _value(0)
 */
Fixed::Fixed(void)
{
	this->_value = 0;
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
/**
 * Should use getRawBits() too
 */
Fixed	&Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		this->_value = obj._value;
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

/*********************************************************************************/
/*                                 ADDED STUFF                                   */
/*********************************************************************************/

/**
 * Equivalent to integer * 2^fractionalBits
 * 
 * fractionalBits accessed using Fixed:: since it's a class property
 */
Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called\n";
	this->setRawBits(integer << Fixed::_fractionalBits);
}

/**
 * Static cast checks at compile time so no overhead
 * 
 * Note that you cannot bit shift floats directly
 * 
 * Equivalent to floatNum * 2^fractionalBits
 */
Fixed::Fixed(const float floatNum)
{
    std::cout << "Float constructor called\n";
	this->_value = static_cast<int>(roundf(floatNum * (1 << Fixed::_fractionalBits)));
}

/**
 * It's technically better to use the getRaWBits() member function here (encapsulation)
 * 
 * Note that you have to cast _value to float first before division and NOT after otherwise
 * you'll lose the precison.
 */
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << Fixed::_fractionalBits));
}

/**
 * Should use getRawBits() too but for easy checking we use this->_value
 */
int		Fixed::toInt(void) const
{
	return (this->_value / (1 << Fixed::_fractionalBits));
}

/**
 * PDF wants this to insert a floating-point representation of the fixed-point number into
 * the output stream object passed as parameter.
 */
std::ostream	&operator<<(std::ostream &newOut, const Fixed &obj)
{
	newOut << obj.toFloat();
	return (newOut);
}
