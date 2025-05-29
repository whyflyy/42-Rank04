/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:20:29 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/29 13:51:49 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie  *zombie;

	zombie = newZombie("Odysseus");
	zombie->announce();

	randomChump("Eurylochus");
	delete zombie;
	return (0);
}
