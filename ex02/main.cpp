/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:31:33 by qtay              #+#    #+#             */
/*   Updated: 2024/11/08 01:18:30 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * 5.05 will be stored as 1293 in _value instead of it's actual 1292.8
 * This means b will lose accuracy wil converted back
 */
int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed c ( Fixed ( 5.5f ));
	std::cout << a << std::endl;
	// std::cout << a + b << std::endl;
	// std::cout << a - b << std::endl;
	// std::cout << c * b << std::endl;
	// std::cout << c / b << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl; //problem
	return (0);
}

