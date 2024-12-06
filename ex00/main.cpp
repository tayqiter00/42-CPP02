/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:31:33 by qtay              #+#    #+#             */
/*   Updated: 2024/12/05 22:09:24 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * Fixed point numbers allow us to represent fractions/decimals using integers
 */
int main( void )
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b :" << b.getRawBits() << std::endl;
	std::cout << "c :" << c.getRawBits() << std::endl;
	return (0);
}