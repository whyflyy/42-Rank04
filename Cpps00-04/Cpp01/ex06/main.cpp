/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:18:49 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/11 12:10:29 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string ToUpper(std::string str)
{
    std::string newstr = str;

    for (size_t i = 0; i < str.length(); i++)
    {
        newstr[i] = std::toupper(str[i]);
    }

    return newstr;
}

int main(int argc, char **argv)
{
	std::string	complaint;

	switch (argc)
	{
		case 1:
			std::cout << "Come on! You must have something to complain!" << std::endl;
			return (1);
		case 2:
			Harl Chato;
			complaint = ToUpper(argv[1]);
			Chato.complain(complaint);
			return (0);
	}
	std::cout << "You complain too much!" << std::endl;
	return (1);
}
