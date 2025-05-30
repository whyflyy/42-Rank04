/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:36:10 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/30 11:20:38 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name)
{
	_name = Name;
	_weapon = NULL;
}

HumanB::HumanB(std::string Name, Weapon &NewWeapon)
{
	_name = Name;
	_weapon = &NewWeapon;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << YELLOW << this->_name << RESET << " has no weapon, so he uses his " << CYAN << "bag of wind" << RESET << std::endl;
	else
		std::cout << YELLOW << this->_name << RESET << " atacks with their " << RED << this->_weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &NewWeapon)
{
	_weapon = &NewWeapon;
}
