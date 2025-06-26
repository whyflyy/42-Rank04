/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:39 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/25 16:55:10 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongAnimal_HPP
#define WRONGWrongAnimal_HPP

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN    	"\033[38;5;87m"
#define ORANGE 		"\033[38;5;208m"

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		//Orthodox Canonical form
		//Default Constructor
		WrongAnimal();
		//Copy Constructor
		WrongAnimal(const WrongAnimal &copy);
		//Copy assignement operator overload
		WrongAnimal &operator=(const WrongAnimal &copy);
		//Destructor
		virtual ~WrongAnimal();

		virtual	void	makeSound(void) const;
		std::string		getType(void) const;
};




#endif