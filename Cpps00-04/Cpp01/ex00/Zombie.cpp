/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:40:57 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/29 12:04:40 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << GREEN << _name << RED << " has been killed!"<< RESET << std::endl; 
}

void    Zombie::announce(void)
{
    std::cout << GREEN << _name << RESET << " BraiiiiiiinnnzzzZ..." << std::endl;
}
