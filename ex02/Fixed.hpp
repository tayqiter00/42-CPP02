/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:17:34 by qtay              #+#    #+#             */
/*   Updated: 2024/11/07 18:16:59 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
// # include <stdbool.h>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floatNum);
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed	&operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
		// Added
		bool	operator<(const Fixed &obj);
		bool	operator>(const Fixed &obj);
		bool	operator<=(const Fixed &obj);
		bool	operator>=(const Fixed &obj);
		bool	operator==(const Fixed &obj);
		bool	operator!=(const Fixed &obj);
		Fixed	operator+(const Fixed &obj);
		Fixed	operator-(const Fixed &obj);
		Fixed	operator*(const Fixed &obj);
		Fixed	operator/(const Fixed &obj);
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);
		
		static Fixed const	&min(Fixed const &obj1, Fixed const &obj2);
		static Fixed const	&max(Fixed const &obj1, Fixed const &obj2);
};

std::ostream	&operator<<(std::ostream &newOut, const Fixed &obj);

#endif
