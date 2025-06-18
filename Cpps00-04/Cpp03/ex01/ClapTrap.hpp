/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:18 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/18 16:22:48 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

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
#include <limits>
#include <string>
#include <cmath>

class ClapTrap
{
	private:
		std::string		_Name;
		unsigned int	_Hp;
		unsigned int	_Ep;
		unsigned int	_Ad;
	public:
		//Orthodox Canonical form
		//Default Constructor
		ClapTrap();
		//Constructor with name
		ClapTrap(std::string Name);
		//Copy Constructor
		ClapTrap(const ClapTrap &copy);
		//Copy assignement operator overload
		ClapTrap &operator=(const ClapTrap &copy);
		//Destructor
		~ClapTrap();

		//member functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		//All functions need to print messages

		//Getters
		std::string		getName(void);
		unsigned int	getEnergy(void);
		unsigned int	getHp(void);
		unsigned int	getDamage(void);
};

#endif