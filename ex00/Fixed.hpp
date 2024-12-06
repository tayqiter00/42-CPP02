/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:17:34 by qtay              #+#    #+#             */
/*   Updated: 2024/11/07 17:11:55 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

/**
 * For C++98, the Orthodox Canonical Form (OCF) in C++ requires the
 * definitions of four special member functions for each Class to properly
 * manage its resources and ensure proper behavior in various scenarios, such
 * as object copying and assignment:
 * 1. Default constructor
 * 2. Copy constructor
 * 3. Destructor
 * 4. Copy assignment operator
 * 
 * If used in a class, a static member belongs to the class itself rather than
 * to any specific instance of the class. This means all instances of the class
 * share the same value of the static member.
 * 
 * Fractional part of the fixed-point numbers will be represented using 8 bits.
 * 
 * A copy constructor is a type of constructor that initializes an object using
 * another object of the same class.
 * 
 * Operator overloading: giving special meaning to an existing operator in C++
 * without changing its original meaning (compile-time polymorphism). Used on
 * class variables or class objects. Here we overload the '=' operator.
 * 
 * A constant member function guarantees not to modify any member variables of
 * the object on which it is called (see getRawBits()).
 */
class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed(void); // Default
		Fixed(const Fixed &obj); // Copy
		~Fixed(); // Destructor
		Fixed	&operator=(const Fixed &obj); // Copy assignment operator
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
