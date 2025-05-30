/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:36:01 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/30 11:20:09 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &NewWeapon) : _weapon(NewWeapon)
{
    _name = name;
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void)
{
    std::cout << YELLOW << this->_name << RESET << " atacks with their " << RED << this->_weapon.getType() << std::endl;
}

