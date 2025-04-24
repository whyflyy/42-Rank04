/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:17:16 by jcavadas          #+#    #+#             */
/*   Updated: 2025/04/24 15:38:53 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void	print_data(std::string str, bool newline)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << std::setfill(' ') << std::setw(10) << str << "|";
	if (newline)
		std::cout << std::endl;
}

static void	print_header(void)
{
	std::cout << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|";
	print_data("Index", false);
	print_data("First Name", false);
	print_data("Last Name", false);
	print_data("Nick Name", true);
	std::cout << "|-------------------------------------------|" << std::endl;
}

static void	print_all_contacts(Phonebook *Phonebook)
{
	for (int i = 0; i < Phonebook->getNumEntries(); i++)
	{
		std::cout << "|";
		std::cout << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		print_data(Phonebook->contacts[i].getName(), false);
		print_data(Phonebook->contacts[i].getLastName(), false);
		print_data(Phonebook->contacts[i].getNickName(), true);
	}
}

static void	print_contact(Contact Contact)
{
	std::cout << std::endl << MAGENTA << "First Name: " << RESET << Contact.getName() << std::endl;
	std::cout << MAGENTA << "Last Name: " << RESET << Contact.getLastName() << std::endl;
	std::cout << MAGENTA << "NickName: " << RESET << Contact.getNickName() << std::endl;
	std::cout << MAGENTA << "Phone Number: " << RESET << Contact.getPhoneNumber() << std::endl;
	std::cout << MAGENTA << "Darkest Secret: " << RESET << Contact.getSecret() << std::endl;
}

void    search_contact(Phonebook *Phonebook)
{
	int index = 0;
	if (Phonebook->getNumEntries() < 1)
		std::cout << YELLOW << "Please Add a Contact before trying to Search" << RESET << std::endl;
	
	print_header();
	print_all_contacts(Phonebook);
	std::cout << "|-------------------------------------------|" << std::endl;
	
	std::cout << BLUE << "Enter index: " << RESET;
	
	if (!(std::cin >> index))
	{
		std::cout << "Invalid index" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else if (index > 0 && index <= Phonebook->getNumEntries())
	{
		print_contact(Phonebook->contacts[index - 1]);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cout << RED << "Invalid Index!" << RESET << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}

}
