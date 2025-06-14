/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:40:49 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/14 16:32:56 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed   getW1(Point a, Point b, Point c, Point p)
{
	Fixed	aX = a.get_X();
	Fixed	aY = a.get_Y();
	Fixed	bX = b.get_X();
	Fixed	bY = b.get_Y();
	Fixed	cX = c.get_X();
	Fixed	cY = c.get_Y();
	Fixed	pX = p.get_X();
	Fixed	pY = p.get_Y();

	//Numerador do w1 da formula baricentrica
	Fixed numerator = (aX * (cY - aY)) + ( (pY - aY) * (cX - aX) ) - (pX * (cY - aY));
	
	//Denominador determinante relativamente a area do triangulo
	Fixed denominator = (bY - aY) * (cX - aX) - (bX - aX) * (cY - aY);
	
	return (numerator/denominator);
}

Fixed	getW2(Point a, Point b, Point c, Point p, Fixed w1)
{
	Fixed	aY = a.get_Y();
	Fixed	bY = b.get_Y();
	Fixed	cY = c.get_Y();
	Fixed	pY = p.get_Y();
	
	return ((pY - aY - w1 * (bY - aY)) / (cY - aY));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1 = getW1(a, b, c, point);
	Fixed w2 = getW2(a, b, c, point, w1);
	Fixed w3 = Fixed(1) - w1 -w2;
	//A soma de w1 com w2 e com w3 tem de ser 1, por isso que se calcula assim o w3
	
	//Todas as weights teem de ser > 0 e < 1;
	return (w1 > 0 && w2 > 0 && w3 > 0);
}