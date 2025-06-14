/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:30:43 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/13 13:59:38 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Tem de ser declarado assim para ser declarado durante a construcao e nao DEPOIS
//Isto acontece porque x e y sao const
Point::Point() : _x(0.0f), _y(0.0f)
{
	//std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

//Constructor from subject
Point::Point(const float x, const float y) : _x(x), _y(y)
{
}
//Copy constructor
Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{	
}
//Copy assignment operator overload
Point &Point::operator=(const Point &copy)
{
	(void)copy;
	return *this;
}

Point::~Point()
{
	//std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed Point::get_X(void) const
{
	return (this->_x);	
}

Fixed Point::get_Y(void) const
{
	return (this->_y);
}
