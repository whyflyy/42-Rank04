/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:28:00 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 11:35:55 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//Default Constructor
Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor Called" << RESET << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

//Copy Constructor
Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << CYAN << "Cat Copy constructor called" << RESET << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}
//Copy assignement operator overload
Cat &Cat::operator=(const Cat &copy)
{
	std::cout << MAGENTA << "Cat Copy assignment operator called" << RESET << std::endl;
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
Cat::~Cat()
{
	std::cout << RED << "Cat Destructor Called" << RESET << std::endl;
	delete this->_brain;
}

void	Cat::makeSound(void) const
{
	std::cout << YELLOW << "*Meowwwww Purrrrr*" << RESET << std::endl;
}

void	Cat::think(unsigned int number)
{
	this->_brain->speakIdeas(this->_type, number);
}

void	Cat::setIdeas(unsigned int index, std::string idea)
{
	index -= 1;
	if (index > 100)
	{
		std::cout << RED << "Cat can't think that many ideas!" << RESET << std::endl;
		return ;
	}
	else
	{
		this->_brain->placeIdeas(index, idea);
		return ;
	}
}

