/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:09:59 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/27 01:16:09 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//Constructor
Animal::Animal()
{
	std::cout << GREEN << "Animal Default Constructor Called" << RESET << std::endl;
	this->_type = "default";
}

//Copy Constructor
Animal::Animal(const Animal &copy)
{
	std::cout << CYAN << "Animal Copy constructor called" << RESET << std::endl;
	this->_type = copy._type;
}
//Copy assignement operator overload
Animal &Animal::operator=(const Animal &copy)
{
	std::cout << MAGENTA << "Animal Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

//Destructor
Animal::~Animal()
{
	std::cout << RED << "Animal Destrutcor Called" << RESET << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
