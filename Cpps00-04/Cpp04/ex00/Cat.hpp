/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:27:45 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/25 16:40:23 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

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

class Cat : public Animal
{
	private:
		/* data */
	public:
		//Orthodox Canonical form
		//Default Constructor
		Cat();
		//Copy Constructor
		Cat(const Cat &copy);
		//Copy assignement operator overload
		Cat &operator=(const Cat &copy);
		//Destructor
		~Cat();

		void	makeSound(void) const;
};

#endif