/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:24:27 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 13:36:18 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define SEPARATOR "\033[38;5;208m\n==============================\n\033[0m"

void wait_for_enter() {
	std::cout << "\nPress ENTER to continue..." << std::endl;
	std::cin.ignore();
	std::cout << "\033[2J\033[H"; // Clear screen
}

int	main(void)
{
	std::cout << SEPARATOR << "Consctructors" << SEPARATOR << std::endl;
	DiamondTrap    Deez;
	DiamondTrap    Dio("Dio");

	wait_for_enter();

	std::cout << SEPARATOR << "Initial values" << SEPARATOR << std::endl;	
	
	std::cout << "DiamondTrap 1: " << Deez.getName() << std::endl;
	std::cout << "HP: " << Deez.getHp() << std::endl;
	std::cout << "Energy Points: " << Deez.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Deez.getDamage() << std::endl;

	std::cout << std::endl;

	std::cout << "DiamondTrap 2: " << Dio.getName() << std::endl;
	std::cout << "HP: " << Dio.getHp() << std::endl;
	std::cout << "Energy Points: " << Dio.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Dio.getDamage() << std::endl;
	
	wait_for_enter();

	std::cout << SEPARATOR << "Attacking" << SEPARATOR << std::endl;	
	
	Deez.attack("Capitalism");
	std::cout << Deez.getName() << "'s Current Energy: " << Deez.getEnergy() << std::endl;

	Dio.attack("Everything");
	std::cout << Dio.getName() << "'s Current Energy: " << Dio.getEnergy() << std::endl;

	wait_for_enter();
	
	std::cout << SEPARATOR << "Taking damage" << SEPARATOR << std::endl;	

	Dio.takeDamage(0);
	std::cout << Dio.getName() << "'s Current HP: " << Dio.getHp() << std::endl;
	
	Dio.takeDamage(42);
	std::cout << Dio.getName() << "'s Current HP: " << Dio.getHp() << std::endl;
	
	Dio.takeDamage(100);
	std::cout << Dio.getName() << "'s Current HP: " << Dio.getHp() << std::endl;
	
	Dio.takeDamage(1);
	std::cout << Dio.getName() << "'s Current HP: " << Dio.getHp() << std::endl;

	wait_for_enter();

	std::cout << SEPARATOR << "Repairing" << SEPARATOR << std::endl;	

	Dio.beRepaired(10);
	std::cout << Dio.getName() << "'s Current HP: " << Dio.getHp() << std::endl;

	std::cout << std::endl;

	Deez.beRepaired(1);
	std::cout << Deez.getName() << "'s Current HP: " << Deez.getHp() << std::endl;
 
	wait_for_enter();

	std::cout << SEPARATOR << "High Fives" << SEPARATOR << std::endl;	

	std::cout << Dio.getName() << "'s Current HP: " << Dio.getHp() << std::endl;
	Dio.highFivesGuys();

	std::cout << std::endl;

	std::cout << Deez.getName() << "'s Current HP: " << Deez.getHp() << std::endl;
	Deez.highFivesGuys();
 
	wait_for_enter();
	
	std::cout << SEPARATOR << "Who am I?" << SEPARATOR << std::endl;	

	Dio.whoAmI();

	std::cout << std::endl;

	Deez.whoAmI();
 
	wait_for_enter();

	std::cout << GREEN << "\nAll tests completed.\n" << RESET;

	
}