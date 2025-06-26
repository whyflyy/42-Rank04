/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:10:08 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 15:14:21 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN    	"\033[38;5;87m"
#define ORANGE 		"\033[38;5;208m"
#define TURQUOISE	"\033[38;5;45m"
#define PEACH		"\033[38;5;217m"

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	_type;
	public:
		//Orthodox Canonical form
		//Default Constructor
		Animal();
		//Copy Constructor
		Animal(const Animal &copy);
		//Copy assignement operator overload
		Animal &operator=(const Animal &copy);
		//Destructor
		virtual ~Animal();

		virtual	void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif