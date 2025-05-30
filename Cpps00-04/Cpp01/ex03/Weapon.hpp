/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:21:08 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/30 10:41:03 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN		"\033[38;5;87m"

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	_type;

	public:
		//Constructor
		Weapon(std::string type);
		//Destructor
		~Weapon();
		//Getter
		const std::string&	getType(void) const;
		//Setter
		void	setType(std::string newType);
};

#endif
