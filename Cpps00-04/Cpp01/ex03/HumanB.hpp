/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:36:30 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/29 16:59:53 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN		"\033[38;5;87m"

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	private:
		Weapon	*_weapon;
		std::string	_name;

	public:
		//Constructor
		HumanB(std::string Name);
		//Destructor
		~HumanB();
		//Member functions
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif
