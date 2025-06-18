/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:04 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/18 09:43:11 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN    	"\033[38;5;87m"
#define ORANGE 		"\033[38;5;208m"

#include <iostream>
#include <limits>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int	_value;
		static const int	_fractional = 8;
	public:
		//////////////////////////////////////////Orthodox Canonical form
		//Default Constructor
		Fixed();
		//Copy Constructor
		Fixed(const Fixed &copy);
		//Copy assignement operator overload
		Fixed &operator=(const Fixed &copy);
		//Destructor
		~Fixed();
		
		//////////////////////////////////////////Extras
		//Constructor with int and float
		Fixed(const int num);
		Fixed(const float num);
		
		//Member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		//////////////////////////////////////////NEW
		//Comparison operators
		bool    operator>(const Fixed &copy);
		bool    operator<(const Fixed &copy);
		bool    operator>=(const Fixed &copy);
		bool    operator<=(const Fixed &copy);
		bool    operator==(const Fixed &copy);
        bool    operator!=(const Fixed &copy);

		//Arithmetic operators
		Fixed	operator+(const Fixed &copy);
		Fixed	operator-(const Fixed &copy);
		Fixed	operator*(const Fixed &copy);
		Fixed	operator/(const Fixed &copy);
		
		//Increment/Decrement operators
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		//Public Overloaded
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
