/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:18:34 by qtay              #+#    #+#             */
/*   Updated: 2024/11/08 01:11:32 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(void)
{
	this->_value = 0;
	// std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	_value = obj._value;
	// std::cout << "Copy constructor called\n";

}

Fixed	&Fixed::operator=(const Fixed &obj)
{
    // std::cout << "Copy assignment operator called\n";
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
	// std::cout << "getRawBits member function called\n";
	return (this->_value);
}

Fixed::Fixed(const int integer)
{
    // std::cout << "Int constructor called\n";
	this->setRawBits(integer << Fixed::_fractionalBits);
}

Fixed::Fixed(const float floatNum)
{
    // std::cout << "Float constructor called\n";
	this->_value = static_cast<int>(roundf(floatNum * (1 << Fixed::_fractionalBits)));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << Fixed::_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_value / (1 << Fixed::_fractionalBits));
}

std::ostream	&operator<<(std::ostream &newOut, const Fixed &obj)
{
	newOut << obj.toFloat();
	return (newOut);
}


/*********************************************************************************/
/*                                 ADDED STUFF                                   */
/*********************************************************************************/

/**
 * None of them returns by reference. They return a value (or a copy) because
 * you're usually interested in the result of these operations, not modifying
 * the original directly.
 */
bool	Fixed::operator<(const Fixed &obj)
{
	return (this->_value < obj._value);
}

bool	Fixed::operator<=(const Fixed &obj)
{
	return (this->_value <= obj._value);
}

bool	Fixed::operator>(const Fixed &obj)
{
	return (this->_value > obj._value);
}

bool	Fixed::operator>=(const Fixed &obj)
{
	return (this->_value >= obj._value);
}

bool	Fixed::operator==(const Fixed &obj)
{
	return (this->_value == obj._value);
}

bool	Fixed::operator!=(const Fixed &obj)
{
	return (this->_value != obj._value);
}

/**
 * Convert to float to carry out mathematical operations. It'll then be converted back to _value
 * by the float Constructor
 */
Fixed	Fixed::operator+(const Fixed &obj)
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &obj)
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

/* Pre-increment: void */
Fixed	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

/* Post-increment: int */
Fixed	Fixed::operator++(int)
{
	Fixed	ret = *this;
	this->_value++;
	return (ret);
}

Fixed	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret = *this;
	this->_value--;
	return (ret);
}

Fixed const	&Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1._value < obj2._value)
		return (obj1);
	return (obj2);
}

Fixed const	&Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1._value > obj2._value)
		return (obj1);
	return (obj2);
}
