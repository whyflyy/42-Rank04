/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:53:16 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/26 14:21:46 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"

//Constructor
Brain::Brain()
{
	std::cout << GREEN << "Brain Default Constructor Called" << RESET << std::endl;
	createIdeas();
}

//Copy Constructor
Brain::Brain(const Brain &copy)
{
	std::cout << CYAN << "Brain Copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
}
//Copy assignement operator overload
Brain &Brain::operator=(const Brain &copy)
{
	std::cout << MAGENTA << "Brain Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = copy._ideas[i];
		}
	}
	return (*this);
}

//Destructor
Brain::~Brain()
{
	std::cout << RED << "Brain Destrutcor Called" << RESET << std::endl;
}

void	Brain::createIdeas(void)
{
	std::cout << ORANGE << "My brain is overloading with ideas!!!" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "I smell like beef";
	}
}

void	Brain::speakIdeas(std::string type, unsigned int number)
{
	if (number > 100)
		number = 100;
	for (unsigned int i = 0; i < number; i++)
	{
		std::cout << "Idea number: " << YELLOW << i + 1 << RESET << ", from "
		<< CYAN << type << PEACH << " : " << this->_ideas[i] << RESET << std::endl;
	}	
}

void	Brain::placeIdeas(unsigned int index ,std::string idea)
{
	this->_ideas[index] = idea;
}
