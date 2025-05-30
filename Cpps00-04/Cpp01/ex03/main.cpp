/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:20:46 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/30 11:24:02 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon Trident("Trident");
	HumanA Poseidon("Poseidon", Trident);
	
	Poseidon.attack();
	Trident.setType("Ocean Powers");
	Poseidon.attack();

	std::cout << std::endl;
	
	Weapon	Sword("Sword");
	HumanB	Odysseus("Odysseus");
	
	Odysseus.attack();
	std::cout << "Odysseus got his sword!" << std::endl;
	Odysseus.setWeapon(Sword);
	Odysseus.attack();

	std::cout << std::endl;

	Trident.setType("Trident");

	std::cout << "Poseidon is down! Odysseus stole his Trident!" << std::endl;
	Odysseus.setWeapon(Trident);
	Odysseus.attack();

	std::cout << "Poseidon has given up and called off the storm. Odysseus gets to go home." << std::endl;
}
