/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:18:49 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/09 17:22:42 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	switch (argc)
	{
		case 1:
			std::cout << "Come on! You must have something to complain!" << std::endl;
			return (1);
		case 2:
			Harl Chato;
			Chato.complain(argv[1]);
			return (0);
	}
	std::cout << "You complain too much!" << std::endl;
	return (1);
}
