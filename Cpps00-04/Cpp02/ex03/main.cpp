/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:25:20 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/14 16:47:14 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

#define SEPARATOR "\033[38;5;208m\n==============================\n\033[0m"

void wait_for_enter() {
	std::cout << "\nPress ENTER to continue..." << std::endl;
	std::cin.ignore();
	std::cout << "\033[2J\033[H"; // Clear screen
}

void test_case(const Point& a, const Point& b, const Point& c, const Point& p) {
	std::cout << "Triangle vertices:\n";
	std::cout << "  A(" << a.get_X() << ", " << a.get_Y() << ")\n";
	std::cout << "  B(" << b.get_X() << ", " << b.get_Y() << ")\n";
	std::cout << "  C(" << c.get_X() << ", " << c.get_Y() << ")\n";
	std::cout << "Test Point:\n";
	std::cout << "  P(" << p.get_X() << ", " << p.get_Y() << ")\n";

	bool result = bsp(a, b, c, p);
	std::cout << "\nResult: ";
	if (result)
		std::cout << GREEN << "INSIDE" << RESET << " the triangle\n";
	else
		std::cout << RED << "OUTSIDE" << RESET << " the triangle\n";
}

int main() {
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 4);

	std::cout << SEPARATOR << "Test 1: Point inside the triangle" << SEPARATOR;
	test_case(a, b, c, Point(2, 1)); // inside
	wait_for_enter();

	std::cout << SEPARATOR << "Test 2: Point on a vertex (A)" << SEPARATOR;
	test_case(a, b, c, Point(0, 0)); // vertex A
	wait_for_enter();

	std::cout << SEPARATOR << "Test 3: Point on edge AB" << SEPARATOR;
	test_case(a, b, c, Point(2, 0)); // edge AB
	wait_for_enter();

	std::cout << SEPARATOR << "Test 4: Point outside the triangle" << SEPARATOR;
	test_case(a, b, c, Point(5, 2)); // outside
	wait_for_enter();

	std::cout << SEPARATOR << "Test 5: Point on edge AC" << SEPARATOR;
	test_case(a, b, c, Point(1, 2)); // edge AC
	wait_for_enter();

	std::cout << SEPARATOR << "Test 6: Point on edge BC" << SEPARATOR;
	test_case(a, b, c, Point(3, 2)); // edge BC
	wait_for_enter();

	std::cout << SEPARATOR << "Test 7: Point at vertex C" << SEPARATOR;
	test_case(a, b, c, Point(2, 4)); // vertex C
	wait_for_enter();

	std::cout << "\nAll tests completed.\n";
	return 0;
}
