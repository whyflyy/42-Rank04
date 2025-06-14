/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:10 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/13 13:57:21 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
	_value = copy.getRawBits();
}

Fixed::Fixed(const int num)
{
	//std::cout << BLUE << "Int contstant constuctor called" << RESET << std::endl;
	_value = num << _fractional;
}

Fixed::Fixed(const float num)
{
	//std::cout << BLUE << "Float constant constructor called" << RESET << std::endl;
	_value = static_cast<int>(roundf(num * (1 << _fractional)));
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	//std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	
	if (this != &copy)
	{
		_value = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << RED << "Destructor called" << RESET << std::endl;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
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
//Nao incrementa por 1, incrementa o _value por 1 -> e adicionar 1/256 (0.00390625) ao numero
//++a
Fixed	&Fixed::operator++()
{
	++_value;
	return (*this);
}

//--a
Fixed	&Fixed::operator--()
{
	--_value;
	return (*this);
}

//a++
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this); //Salva o valor atual
	++_value; //Incrementa na var
	return (tmp); //Devolve o valor antes do incremento
}

//a--
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--_value;
	return (tmp);
}

//Overloaded member functions
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value < b._value)
		return (a);
	else
		return (b);	
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value > b._value)
		return (a);
	else
		return (b);	
}
