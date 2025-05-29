/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:56:30 by jcavadas          #+#    #+#             */
/*   Updated: 2025/03/02 22:56:30 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "phonebook.hpp"

void    ft_add_contact(Phonebook *Phonebook)
{
	std::string Name, LastName, Nickname, PhoneNumber, Secret;

	while (Name.empty()){
		std::cout << BLUE << "Enter First Name please! :) " << RESET;
		std::getline(std::cin, Name);
		if (Name.empty())
			std::cout << CYAN << "First name cannot be empty. Please enter again! :(" << RESET << std::endl;
	}

	while (LastName.empty()){
		std::cout << BLUE << "Enter Last Name please! :) " << RESET;
		std::getline(std::cin, LastName);
		if (LastName.empty())
			std::cout << CYAN << "Last name cannot be empty. Please enter again! :(" << RESET << std::endl;
	}

	while (Nickname.empty()){
		std::cout << BLUE << "Enter Nickname please! :) " << RESET;
		std::getline(std::cin, Nickname);
		if (Nickname.empty())
			std::cout << CYAN << "Nickname cannot be empty. Please enter again! :(" << RESET << std::endl;
	}

	while (PhoneNumber.empty()){
		std::cout << BLUE << "Enter Phone Number please! :) " << RESET;
		std::getline(std::cin, PhoneNumber);
		if (PhoneNumber.empty())
			std::cout << CYAN << "Phone Number cannot be empty. Please enter again! :(" << RESET << std::endl;
	}

	while (Secret.empty()){
		std::cout << BLUE << "Enter your darkest secret! I swear I won't tell anyone :) " << RESET;
		std::getline(std::cin, Secret);
		if (Secret.empty())
			std::cout << CYAN << "Oh come on! I know you must have at least one secret! :(" << RESET << std::endl;
	}
	Phonebook->addContact(Name, LastName, Nickname, PhoneNumber, Secret);
}
