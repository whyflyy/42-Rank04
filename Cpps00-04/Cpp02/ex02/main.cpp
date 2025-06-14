/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:16:56 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/13 13:24:23 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


void waitForEnter(const std::string& msg = "\nPress ENTER to continue...\n") {
	std::cout << msg;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\033[2J\033[H";
}

int main()
{    
	std::cout << ORANGE << "========== 0. Subject tests ==========\n" << RESET;
    Fixed f;
    Fixed const g( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << f << std::endl;
    std::cout << ++f << std::endl;
    std::cout << f << std::endl;
    std::cout << f++ << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    std::cout << Fixed::max( f, g ) << std::endl;

	waitForEnter();
    
	std::cout << ORANGE << "========== 1. Constructors ==========\n" << RESET;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	waitForEnter();

	std::cout << ORANGE << "========== 2. Assignment ==========\n" << RESET;
	a = Fixed(1234.4321f);

	waitForEnter();

	std::cout << ORANGE << "========== 3. toFloat / toInt / << operator ==========\n" << RESET;
	std::cout << "a is " << a << " (float)" << std::endl;
	std::cout << "a is " << a.toInt() << " (int)" << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	waitForEnter();

	std::cout << ORANGE << "========== 4. Comparison operators ==========\n" << RESET;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
    std::cout << std::boolalpha;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	waitForEnter();

	std::cout << ORANGE << "========== 5. Arithmetic operators ==========\n" << RESET;
	Fixed x(5.5f);
	Fixed y(2);

	std::cout << "x: " << x << ", y: " << y << std::endl;
	std::cout << "x + y: " << (x + y) << std::endl;
	std::cout << "x - y: " << (x - y) << std::endl;
	std::cout << "x * y: " << (x * y) << std::endl;
	std::cout << "x / y: " << (x / y) << std::endl;

	waitForEnter();

	std::cout << ORANGE << "========== 6. Increment / Decrement operators ==========\n" << RESET;
	Fixed inc;
	std::cout << "Initial: " << inc << std::endl;

	std::cout << "++inc: " << ++inc << std::endl;
	std::cout << "inc++: " << inc++ << std::endl;
	std::cout << "After inc++: " << inc << std::endl;

	std::cout << "--inc: " << --inc << std::endl;
	std::cout << "inc--: " << inc-- << std::endl;
	std::cout << "After inc--: " << inc << std::endl;

	waitForEnter();

	std::cout << ORANGE << "========== 7. Min / Max static functions ==========\n" << RESET;
	Fixed n1(3.3f);
	Fixed n2(7.7f);

	std::cout << "n1: " << n1 << ", n2: " << n2 << std::endl;
	std::cout << "Min: " << Fixed::min(n1, n2) << std::endl;
	std::cout << "Max: " << Fixed::max(n1, n2) << std::endl;

	const Fixed cn1(1.1f);
	const Fixed cn2(9.9f);
	std::cout << "Const Min: " << Fixed::min(cn1, cn2) << std::endl;
	std::cout << "Const Max: " << Fixed::max(cn1, cn2) << std::endl;

	waitForEnter("\nAll tests done! Press ENTER to exit.\n");

	return 0;
}

