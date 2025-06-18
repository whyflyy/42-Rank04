/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:37:36 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/18 15:37:18 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define SEPARATOR "\033[38;5;208m\n==============================\n\033[0m"

void wait_for_enter() {
	std::cout << "\nPress ENTER to continue..." << std::endl;
	std::cin.ignore();
	std::cout << "\033[2J\033[H"; // Clear screen
}

int	main(void)
{
	std::cout << SEPARATOR << "Consctructors" << SEPARATOR << std::endl;	

	ClapTrap Dude("Dude");
	ClapTrap Joe;

	wait_for_enter();

	std::cout << SEPARATOR << "Initial values" << SEPARATOR << std::endl;	
	
	std::cout << "Claptrap 1: " << Dude.getName() << std::endl;
	std::cout << "HP: " << Dude.getHp() << std::endl;
	std::cout << "Energy Points: " << Dude.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Dude.getDamage() << std::endl;

	std::cout << std::endl;

	std::cout << "Claptrap 2: " << Joe.getName() << std::endl;
	std::cout << "HP: " << Joe.getHp() << std::endl;
	std::cout << "Energy Points: " << Joe.getEnergy() << std::endl;
	std::cout << "Attack Damage: " << Joe.getDamage() << std::endl;
	
	wait_for_enter();

	std::cout << SEPARATOR << "Attacking" << SEPARATOR << std::endl;	
	
	Dude.attack("Capitalism");
	std::cout << Dude.getName() << "'s Current Energy: " << Dude.getEnergy() << std::endl;

	Joe.attack("Everything");
	std::cout << Joe.getName() << "'s Current Energy: " << Joe.getEnergy() << std::endl;

	int	i = 0;
	while (i < 9)
	{
		Dude.attack("A lot");
		std::cout << Dude.getName() << "'s Current Energy: " << Dude.getEnergy() << std::endl;	
		i++;
	}

	Dude.attack("The air");
	std::cout << Dude.getName() << "'s Current Energy: " << Dude.getEnergy() << std::endl;

	wait_for_enter();

	std::cout << SEPARATOR << "Taking damage" << SEPARATOR << std::endl;	

	Dude.takeDamage(0);
	std::cout << Dude.getName() << "'s Current HP: " << Dude.getHp() << std::endl;
	
	Dude.takeDamage(1);
	std::cout << Dude.getName() << "'s Current HP: " << Dude.getHp() << std::endl;
	
	Dude.takeDamage(4);
	std::cout << Dude.getName() << "'s Current HP: " << Dude.getHp() << std::endl;
	
	Dude.takeDamage(5);
	std::cout << Dude.getName() << "'s Current HP: " << Dude.getHp() << std::endl;

	Dude.takeDamage(2);
	std::cout << Dude.getName() << "'s Current HP: " << Dude.getHp() << std::endl;

	wait_for_enter();

	std::cout << SEPARATOR << "Repairing" << SEPARATOR << std::endl;	

	Dude.beRepaired(10);
	std::cout << Dude.getName() << "'s Current HP: " << Dude.getHp() << std::endl;

	std::cout << std::endl;

	//Ele chega aqui so com 9 de energia porque ele ataca uma vez nos testes de ataque
	Joe.beRepaired(1);
	std::cout << Joe.getName() << "'s Current HP: " << Joe.getHp() << std::endl;
 
	i = 0;
	while (i < 9)
	{
		Joe.beRepaired(1);
		std::cout << Joe.getName() << "'s Current Energy: " << Joe.getEnergy() << std::endl;	
		i++;
	}
	std::cout << Joe.getName() << "'s Current HP: " << Joe.getHp() << std::endl;
	
	wait_for_enter();	

	std::cout << GREEN << "\nAll tests completed.\n" << RESET;

	return (0);
}