/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:28:06 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 11:29:49 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


//Default Constructor
Dog::Dog() : Animal()
{
	std::cout << GREEN << "Dog Default Constructor Called" << RESET << std::endl;
	this->_type = "Dog";
}

//Copy Constructor
Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << CYAN << "Dog Copy constructor called" << RESET << std::endl;
	this->_type = copy._type;
}
//Copy assignement operator overload
Dog &Dog::operator=(const Dog &copy)
{
	std::cout << MAGENTA << "Dog Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

//Destructor
Dog::~Dog()
{
	std::cout << RED << "Dog Destructor Called" << RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << YELLOW << "*Bark! Woof! Bark!*" << RESET << std::endl;
}
