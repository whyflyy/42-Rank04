/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:52:27 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/25 17:17:39 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//Default Constructor
WrongCat::WrongCat()
{
	std::cout << GREEN << "WrongCat Default Constructor Called" << RESET << std::endl;
	this->_type = "WrongCat";
}

//Copy Constructor
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
	std::cout << CYAN << "WrongCat Copy constructor called" << RESET << std::endl;
	this->_type = copy._type;
}
//Copy assignement operator overload
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << MAGENTA << "WrongCat Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

//Destructor
WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat Destructor Called" << RESET << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << YELLOW << "*Woof? Bark? Chirp?*" << RESET << std::endl;
}
