/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:52:13 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/25 17:07:51 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGWrongCat_HPP
#define WRONGWrongCat_HPP

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

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		/* data */
	public:
		//Orthodox Canonical form
		//Default Constructor
		WrongCat();
		//Copy Constructor
		WrongCat(const WrongCat &copy);
		//Copy assignement operator overload
		WrongCat &operator=(const WrongCat &copy);
		//Destructor
		~WrongCat();

		void	makeSound(void) const;
};



#endif