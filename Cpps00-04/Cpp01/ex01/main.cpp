/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:11:11 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/29 16:18:30 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*horde;
	int		N = -1;

	horde = zombieHorde(N, "Athena");

	if (!horde)
	{
		std::cout << RED << "The cure for zombies has been discovered and the horde has been prevented!" << RESET << std::endl;
		return (1);
	}
	
	for(int i = 0; i < N; i++)
	{
		std::cout << YELLOW << "Zombie " << i + 1 << ": " << RESET;
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
