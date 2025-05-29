/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:26:00 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/29 16:56:17 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN    	"\033[38;5;87m"

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		//Constructor
		Zombie(std::string name);
		//Destructor
		~Zombie();
		
		//Member functions
		void announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
