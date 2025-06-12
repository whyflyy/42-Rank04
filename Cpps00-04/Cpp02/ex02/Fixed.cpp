/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:10 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/12 16:58:06 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

//////////////////////////////////////////NEW//////////////////////////////////////////NEW//////////////////////////////////////////NEW

//Comparison operators

bool	Fixed::operator>(const Fixed &copy)
{
	return (this->_value > copy._value);
}

bool	Fixed::operator<(const Fixed &copy)
{
	return (this->_value < copy._value);
}

bool	Fixed::operator>=(const Fixed &copy)
{
	return (this->_value >= copy._value);
}

bool	Fixed::operator<=(const Fixed &copy)
{
	return (this->_value <= copy._value);
}

bool	Fixed::operator==(const Fixed &copy)
{
	return (this->_value == copy._value);
}

bool	Fixed::operator!=(const Fixed &copy)
{
	return (this->_value != copy._value);
}

//Arithmetic operators

Fixed	Fixed::operator+(const Fixed &copy)
{
	return (this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-(const Fixed &copy)
{
	return (this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator*(const Fixed &copy)
{
	return (this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed &copy)
{
	return (this->toFloat() / copy.toFloat());
}

//Increment/Decrement operators
//++a
Fixed	&Fixed::operator++()
{

}

//--a
Fixed	&Fixed::operator--()
{
	
}

//a++
Fixed	Fixed::operator++(int)
{
	
}

//a--
Fixed	Fixed::operator--(int)
{
	
}