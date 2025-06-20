/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:58:47 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 12:36:54 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


//Default Constructor
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN << "FragTrap Default constructor called" << RESET << std::endl;
	this->_Hp = 100;
	this->_Ep = 100;
	this->_Ad = 30;
}

//Named Constructor
FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << GREEN << "FragTrap Name constructor called" << RESET << std::endl;
	this->_Hp = 100;
	this->_Ep = 100;
	this->_Ad = 30;
}

//Copy Constructor
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << CYAN << "FragTrap Copy constructor called" << RESET << std::endl;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Ep = copy._Ep;
	this->_Ad = copy._Ad;
}

//Copy assignement operator overload
FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << MAGENTA << "FragTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_Name = copy._Name;
		this->_Hp = copy._Hp;
		this->_Ep = copy._Ep;
		this->_Ad = copy._Ad;	
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap Default destructor called" << RESET << std::endl;
	
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_Hp <= 0)
	{
		std::cout << "FragTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is dead, High Fiving a corpse is weird :/" << std::endl; 
	}
	else
	{
		std::cout << "FragTrap " << YELLOW << this->_Name << RESET;
		std::cout << " distributed High Fives all around!" << std::endl; 
	}
}
