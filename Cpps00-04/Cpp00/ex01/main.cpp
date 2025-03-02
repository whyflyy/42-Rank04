/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:03:53 by jcavadas          #+#    #+#             */
/*   Updated: 2025/03/02 17:03:53 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "phonebook.hpp"

void	print_banner(void)
{
	const std::string RED_NEW = "\033[38;5;9m";  // Background blue
	
	// Print banner with tabs and slashes
    std::cout << MAGENTA;
	std::cout << std::endl << std::endl;
    std::cout << "\n\t██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗   █████╗   █████╗  ██   ██  " << std::endl;
    std::cout << "\t██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗ ██╔═══██╗██╔═══██╗██  ██  " << std::endl;
    std::cout << "\t██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝ ██║   ██║██║   ██║█████ " << std::endl;
    std::cout << "\t██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗ ██║   ██║██║   ██║██   ██  " << std::endl;
    std::cout << "\t██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝ ╚██████╔╝ ╚█████╔╝██    ██     " << std::endl;
    std::cout << "\t╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝══════╝   ╚═════╝   ╚════╝        " << std::endl;
    std::cout << RESET << std::endl;
}

std::string ToUpper(std::string str)
{
    std::string newstr = str;  // Copy original string to allocate space

    for (size_t i = 0; i < str.length(); i++)
    {
        newstr[i] = std::toupper(str[i]);  // Use indexing, not pointers
    }

    return newstr;
}

int	main(void)
{
	std::string	command;
	Phonebook Phonebook;

	print_banner();
	while (1)
	{
		std::cout << std::endl << "Type ADD to create a new contact, SEARCH to search for one, or EXIT to leave the program" << std::endl;
		std::cout << "Enter command: ";
		if (!(std::getline(std::cin, command)))
			return (1);
		command = ToUpper(command);
		if (command.compare("ADD") == 0) //TODO fazer funcao que permite usar comando minusculo ou maiusculo (add ou ADD ou ate outros casos (AdD?))
			ft_add_contact(&Phonebook);
		//std::cout << "You will be able to add soon !:)" << std::endl; //TODO: add_contact
		else if (command.compare("SEARCH") == 0) //TODO fazer funcao que permite usar comando minusculo ou maiusculo (add ou ADD ou ate outros casos (AdD?))
			std::cout << "What do you seek?" << std::endl; //TODO search_contact
		else if (command.compare("EXIT") == 0) //TODO fazer funcao que permite usar comando minusculo ou maiusculo (add ou ADD ou ate outros casos (AdD?))
		{
			std::cout << RED << "Exiting program" << RESET << std::endl;
			break ;
		}
		else
			std::cout << RED << "Invalid Command" << RESET << std::endl;
	}	

	return (0);
}