/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:51:37 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 13:23:11 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_Name;
	public:
		//Orthodox Canonical form
		//Default Constructor
		DiamondTrap();
		//Constructor with name
		DiamondTrap(std::string Name);
		//Copy Constructor
		DiamondTrap(const DiamondTrap &copy);
		//Copy assignement operator overload
		DiamondTrap &operator=(const DiamondTrap &copy);
		//Destructor
		~DiamondTrap();

		//Member functions
		void	whoAmI(void);
		using	ScavTrap::attack;
};

#endif