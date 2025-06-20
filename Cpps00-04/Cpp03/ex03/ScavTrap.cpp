/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:46:46 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 13:19:44 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int const ScavTrap::_scavEp = 50;

//Default Constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GREEN << "ScavTrap Default constructor called" << RESET << std::endl;
	this->_Hp = 100;
	this->_Ep = 50;
	this->_Ad = 20;
	this->_guardState = false;
}

//Named Constructor
ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << GREEN << "ScavTrap Name constructor called" << RESET << std::endl;
	this->_Hp = 100;
	this->_Ep = 50;
	this->_Ad = 20;
	this->_guardState = false;
}

//Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << CYAN << "ScavTrap Copy constructor called" << RESET << std::endl;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Ep = copy._Ep;
	this->_Ad = copy._Ad;
}

//Copy assignement operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << MAGENTA << "ScavTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_Name = copy._Name;
		this->_Hp = copy._Hp;
		this->_Ep = copy._Ep;
		this->_Ad = copy._Ad;	
	}
	return (*this);
}

//Desructor
ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap Default destructor called" << RESET << std::endl;
	
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_Hp <= 0)
	{
		std::cout << "ScavTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is dead, and corpses can't attack :(" << std::endl; 
	}
	else if (this->_Ep <= 0)
	{
		std::cout << "ScavTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is lazy and won't attack!" << std::endl;	
	}
	else
	{
		std::cout <<  "ScavTrap " << YELLOW << this->_Name << RESET;
		std::cout << " attacks " << ORANGE << target << RESET;
		std::cout << " causing " << RED << this->_Ad << RESET << " points of damage!" << std::endl;
		this->_Ep -= 1;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_Hp <= 0)
	{
		std::cout << "ScavTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is dead, corpses don't make good guards :(" << std::endl;
		return ;
	}
	if (_guardState == false)
	{
		this->_guardState = true;
		std::cout << "ScavTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is now guarding the Gate!" << std::endl;
	}
	else
	{
		this->_guardState = false;
		std::cout << "ScavTrap " << YELLOW << this->_Name << RESET;
		std::cout << " has left the Gate!" << std::endl;
	}
}
