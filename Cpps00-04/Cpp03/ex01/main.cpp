/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:45:51 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 12:42:02 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define SEPARATOR "\033[38;5;208m\n==============================\n\033[0m"

void wait_for_enter() {
	std::cout << "\nPress ENTER to continue..." << std::endl;
	std::cin.ignore();
	std::cout << "\033[2J\033[H"; // Clear screen
}

int main(void)
{
	std::cout << SEPARATOR << "Consctructors" << SEPARATOR << std::endl;
    ScavTrap    Scandinavian;
    ScavTrap    Scrappy("Scrappy");

    wait_for_enter();

    std::cout << SEPARATOR << "Initial values" << SEPARATOR << std::endl;	
	
	std::cout << "ScavTrap 1: " << Scandinavian.getName() << std::endl;
	std::cout << "HP: " << Scandinavian.getHp() << std::endl;
	std::cout << "Energy Points: " << Scandinavian.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Scandinavian.getDamage() << std::endl;

	std::cout << std::endl;

	std::cout << "ScavTrap 2: " << Scrappy.getName() << std::endl;
	std::cout << "HP: " << Scrappy.getHp() << std::endl;
	std::cout << "Energy Points: " << Scrappy.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Scrappy.getDamage() << std::endl;
	
	wait_for_enter();

    std::cout << SEPARATOR << "Attacking" << SEPARATOR << std::endl;	
	
	Scandinavian.attack("Capitalism");
	std::cout << Scandinavian.getName() << "'s Current Energy: " << Scandinavian.getEnergy() << std::endl;

	Scrappy.attack("Everything");
	std::cout << Scrappy.getName() << "'s Current Energy: " << Scrappy.getEnergy() << std::endl;

	wait_for_enter();
    
	std::cout << SEPARATOR << "Taking damage" << SEPARATOR << std::endl;	

	Scrappy.takeDamage(0);
	std::cout << Scrappy.getName() << "'s Current HP: " << Scrappy.getHp() << std::endl;
	
	Scrappy.takeDamage(42);
	std::cout << Scrappy.getName() << "'s Current HP: " << Scrappy.getHp() << std::endl;
	
	Scrappy.takeDamage(100);
	std::cout << Scrappy.getName() << "'s Current HP: " << Scrappy.getHp() << std::endl;
	
    Scrappy.takeDamage(1);
	std::cout << Scrappy.getName() << "'s Current HP: " << Scrappy.getHp() << std::endl;

	wait_for_enter();

    std::cout << SEPARATOR << "Repairing" << SEPARATOR << std::endl;	

	Scrappy.beRepaired(10);
	std::cout << Scrappy.getName() << "'s Current HP: " << Scrappy.getHp() << std::endl;

	std::cout << std::endl;

	Scandinavian.beRepaired(1);
	std::cout << Scandinavian.getName() << "'s Current HP: " << Scandinavian.getHp() << std::endl;
 
    wait_for_enter();	

    std::cout << SEPARATOR << "Guarding the Gate" << SEPARATOR << std::endl;	

	std::cout << Scrappy.getName() << "'s Current HP: " << Scrappy.getHp() << std::endl;
	Scrappy.guardGate();

	std::cout << std::endl;

	std::cout << Scandinavian.getName() << "'s Current HP: " << Scandinavian.getHp() << std::endl;
	Scandinavian.guardGate();
	Scandinavian.guardGate();
 
    wait_for_enter();
	
	std::cout << GREEN << "\nAll tests completed.\n" << RESET;

	return  (0);
}
