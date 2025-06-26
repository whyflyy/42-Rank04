/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:28:00 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 11:29:35 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//Default Constructor
Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor Called" << RESET << std::endl;
	this->_type = "Cat";
}

//Copy Constructor
Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << CYAN << "Cat Copy constructor called" << RESET << std::endl;
	this->_type = copy._type;
}
//Copy assignement operator overload
Cat &Cat::operator=(const Cat &copy)
{
	std::cout << MAGENTA << "Cat Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

//Destructor
Cat::~Cat()
{
	std::cout << RED << "Cat Destructor Called" << RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << "*Meowwwww Purrrrr*" << RESET << std::endl;
}
