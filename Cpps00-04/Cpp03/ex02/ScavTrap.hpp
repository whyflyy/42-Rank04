/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:46:57 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 11:57:01 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guardState;
	public:
		//Orthodox Canonical form
		//Default Constructor
		ScavTrap();
		//Constructor with name
		ScavTrap(std::string Name);
		//Copy Constructor
		ScavTrap(const ScavTrap &copy);
		//Copy assignement operator overload
		ScavTrap &operator=(const ScavTrap &copy);
		//Destructor
		~ScavTrap();

		//Member functions
		void	guardGate(void);
		void	attack(const std::string& target);
};

#endif