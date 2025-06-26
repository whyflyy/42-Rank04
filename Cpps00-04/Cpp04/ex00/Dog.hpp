/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:28:19 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/25 16:50:13 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN    	"\033[38;5;87m"
#define ORANGE 		"\033[38;5;208m"

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		/* data */
	public:
		//Orthodox Canonical form
		//Default Constructor
		Dog();
		//Copy Constructor
		Dog(const Dog &copy);
		//Copy assignement operator overload
		Dog &operator=(const Dog &copy);
		//Destructor
		~Dog();

		void	makeSound(void) const;
};

#endif