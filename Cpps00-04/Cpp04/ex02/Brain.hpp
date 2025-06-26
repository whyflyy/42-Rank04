/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:53:27 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 14:22:32 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

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

class Brain
{
	protected:
		std::string	_ideas[100];
	public:
		//Orthodox Canonical form
		//Default Constructor
		Brain();
		//Copy Constructor
		Brain(const Brain &copy);
		//Copy assignement operator overload
		Brain &operator=(const Brain &copy);
		//Destructor
		virtual ~Brain();

		//Member functions
		void	createIdeas(void);
		void	speakIdeas(std::string type, unsigned int number);
		void	placeIdeas(unsigned int index, std::string idea);
};

#endif