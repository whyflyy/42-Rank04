/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:28:06 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 13:50:24 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//Default Constructor
Dog::Dog() : Animal()
{
	std::cout << GREEN << "Dog Default Constructor Called" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

//Copy Constructor
Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << CYAN << "Dog Copy constructor called" << RESET << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}
//Copy assignement operator overload
Dog &Dog::operator=(const Dog &copy)
{
	std::cout << MAGENTA << "Dog Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete this->_brain;
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

//Destructor
Dog::~Dog()
{
	std::cout << RED << "Dog Destructor Called" << RESET << std::endl;
	delete this->_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << YELLOW << "*Bark! Woof! Bark!*" << RESET << std::endl;
}

void	Dog::think(unsigned int number)
{
	this->_brain->speakIdeas(this->_type, number);
}

void	Dog::setIdeas(unsigned int index, std::string idea)
{
	index -= 1;
	if (index > 100)
	{
		std::cout << RED << "Dog can't think that many ideas!" << RESET << std::endl;
		return ;
	}
	else
	{
		this->_brain->placeIdeas(index, idea);
		return ;
	}
}
