/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:57 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/25 16:58:28 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//Constructor
WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal Default Constructor Called" << RESET << std::endl;
	this->_type = "default";
}

//Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << CYAN << "WrongAnimal Copy constructor called" << RESET << std::endl;
	this->_type = copy._type;
}
//Copy assignement operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << MAGENTA << "WrongAnimal Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

//Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destrutcor Called" << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << YELLOW << "*Wrong Animal Noises*" << RESET << std::endl;
}
