/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:58:15 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 12:43:54 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define SEPARATOR "\033[38;5;208m\n==============================\n\033[0m"

void wait_for_enter() {
	std::cout << "\nPress ENTER to continue..." << std::endl;
	std::cin.ignore();
	std::cout << "\033[2J\033[H"; // Clear screen
}

int	main(void)
{
	std::cout << SEPARATOR << "Consctructors" << SEPARATOR << std::endl;
	FragTrap    Fabulous;
	FragTrap    Fantastic("Fantastic");

	wait_for_enter();

	std::cout << SEPARATOR << "Initial values" << SEPARATOR << std::endl;	
	
	std::cout << "FragTrap 1: " << Fabulous.getName() << std::endl;
	std::cout << "HP: " << Fabulous.getHp() << std::endl;
	std::cout << "Energy Points: " << Fabulous.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Fabulous.getDamage() << std::endl;

	std::cout << std::endl;

	std::cout << "FragTrap 2: " << Fantastic.getName() << std::endl;
	std::cout << "HP: " << Fantastic.getHp() << std::endl;
	std::cout << "Energy Points: " << Fantastic.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Fantastic.getDamage() << std::endl;
	
	wait_for_enter();

	std::cout << SEPARATOR << "Attacking" << SEPARATOR << std::endl;	
	
	Fabulous.attack("Capitalism");
	std::cout << Fabulous.getName() << "'s Current Energy: " << Fabulous.getEnergy() << std::endl;

	Fantastic.attack("Everything");
	std::cout << Fantastic.getName() << "'s Current Energy: " << Fantastic.getEnergy() << std::endl;

	wait_for_enter();
	
	std::cout << SEPARATOR << "Taking damage" << SEPARATOR << std::endl;	

	Fantastic.takeDamage(0);
	std::cout << Fantastic.getName() << "'s Current HP: " << Fantastic.getHp() << std::endl;
	
	Fantastic.takeDamage(42);
	std::cout << Fantastic.getName() << "'s Current HP: " << Fantastic.getHp() << std::endl;
	
	Fantastic.takeDamage(100);
	std::cout << Fantastic.getName() << "'s Current HP: " << Fantastic.getHp() << std::endl;
	
	Fantastic.takeDamage(1);
	std::cout << Fantastic.getName() << "'s Current HP: " << Fantastic.getHp() << std::endl;

	wait_for_enter();

	std::cout << SEPARATOR << "Repairing" << SEPARATOR << std::endl;	

	Fantastic.beRepaired(10);
	std::cout << Fantastic.getName() << "'s Current HP: " << Fantastic.getHp() << std::endl;

	std::cout << std::endl;

	Fabulous.beRepaired(1);
	std::cout << Fabulous.getName() << "'s Current HP: " << Fabulous.getHp() << std::endl;
 
	wait_for_enter();

	std::cout << SEPARATOR << "High Fives" << SEPARATOR << std::endl;	

	std::cout << Fantastic.getName() << "'s Current HP: " << Fantastic.getHp() << std::endl;
	Fantastic.highFivesGuys();

	std::cout << std::endl;

	std::cout << Fabulous.getName() << "'s Current HP: " << Fabulous.getHp() << std::endl;
	Fabulous.highFivesGuys();
 
	wait_for_enter();

	std::cout << GREEN << "\nAll tests completed.\n" << RESET;

	return  (0);
}