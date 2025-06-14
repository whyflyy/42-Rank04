/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:30:50 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/13 13:46:55 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		//////////////////////////////////////////Orthodox Canonical form
		//Default Constructor
		Point();
		//Constructor from subject
		Point(const float x, const float y);
		//Copy constructor
		Point(const Point &copy);
		//Copy assignment operator overload
		Point &operator=(const Point &copy);
		//Destructor
		~Point();

		//////////////////////////////////////////Others
		//Member functions
		Fixed get_X(void) const;
		Fixed get_Y(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
//a, b, c -> Vertices of the triangle
//point -> Point to check
//Returns	-> true if point is in the triangle
//			-> false if its outside, on a vertex or edge

#endif