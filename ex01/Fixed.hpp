/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:17:34 by qtay              #+#    #+#             */
/*   Updated: 2024/11/07 18:05:32 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

/**
 * 
 */
class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed(void);
		Fixed(const int integer); // ADDED
		Fixed(const float floatNum); // ADDED
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed	&operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const; // ADDED
		int		toInt(void) const; // ADDED
};

std::ostream	&operator<<(std::ostream &newOut, const Fixed &obj); // ADDED

#endif
