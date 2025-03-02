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

void    ft_add_contact(Phonebook *Phonebook){
    std::string Name, LastName, Nickname, PhoneNumber, Secret;

    while (1){
        std::cout << BLUE << "Enter First Name please! :) " << RESET;
        std::getline(std::cin, Name);
        if (Name.empty()){
            std::cout << CYAN << "First name cannot be empty. Please enter again! :(" << RESET << std::endl;
            continue ;
        }

        (void) Phonebook;
        break ;
    }
}