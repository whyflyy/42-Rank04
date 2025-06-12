/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:31:51 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/12 13:40:31 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
	_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	
	if (this != &copy)
	{
		_value = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << BLUE << "Int contstant constuctor called" << RESET << std::endl;
	_value = num << _fractional;
}

Fixed::Fixed(const float num)
{
	std::cout << BLUE << "Float constant constructor called" << RESET << std::endl;
	_value = static_cast<int>(roundf(num * (1 << _fractional)));
}

int		Fixed::getRawBits(void) const
{
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float> (_value) / (1 << _fractional);
}

int		Fixed::toInt(void) const
{
	return _value >> _fractional;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat(); // print the float version of the fixed-point number
	return out;
}	
