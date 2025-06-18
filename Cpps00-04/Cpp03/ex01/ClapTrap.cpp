/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:10 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/18 14:18:04 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Default constructor
ClapTrap::ClapTrap()
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	_Name = "default";
	_Hp = 10;
	_Ep = 10;
	_Ad = 0;
}

ClapTrap::ClapTrap(std::string Name)
{
	std::cout << GREEN << "Name constructor called" << RESET << std::endl;
	_Name = Name;
	_Hp = 10;
	_Ep = 10;
	_Ad = 0;
}

//Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Ep = copy._Ep;
	this->_Ad = copy._Ad;
}
//Copy assignement operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_Name = copy._Name;
		this->_Hp = copy._Hp;
		this->_Ep = copy._Ep;
		this->_Ad = copy._Ad;	
	}
	return (*this);
}

//Destructor
ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

//Getters
std::string ClapTrap::getName(void)
{
	return (this->_Name);
}

unsigned int ClapTrap::getEnergy(void)
{
	return (this->_Ep);
}
unsigned int ClapTrap::getHp(void)
{	
	return (this->_Hp);
}

unsigned int ClapTrap::getDamage(void)
{
	return (this->_Ad);
}

//All functions need to print messages
void	ClapTrap::attack(const std::string& target)
{
	if (this->_Hp <= 0)
	{
		std::cout << "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is dead, it cannot attack from the grave :(" << std::endl; 
	}
	else if (this->_Ep <= 0)
	{
		std::cout << "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is too tired to attack!" << std::endl;	
	}
	else
	{
		std::cout <<  "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " attacks " << ORANGE << target << RESET;
		std::cout << " causing " << RED << this->_Ad << RESET << " damage!" << std::endl;
		this->_Ep -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hp <= 0)
	{
		std::cout <<  "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is already dead, why are you still hitting them? That's rude!" << std::endl;
	}
	else
	{
		std::cout <<  "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " has taken " << RED << amount << RESET << " damage!" << std::endl;
		
		int	tmp_hp = this->_Hp;

		tmp_hp -= amount;

		if (tmp_hp <= 0)
			tmp_hp = 0;
		this->_Hp = tmp_hp;
		if (this->_Hp <= 0)
		{
			std::cout <<  "ClapTrap " << YELLOW << this->_Name << RESET;
			std::cout << " is now " << RED << " DEAD! " << RESET << " Are you happy now?" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hp <= 0)
	{
		std::cout <<  "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is already dead, it's no use healing them now!" << std::endl;
	}
	else if (this->_Ep <= 0)
	{
		std::cout <<  "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " is too tired to repair themselves!" << std::endl;
	}
	else
	{
		std::cout <<  "ClapTrap " << YELLOW << this->_Name << RESET;
		std::cout << " healed itself for " << GREEN << amount << RESET << " HP!" << std::endl;
		this->_Hp += amount;
		this->_Ep -= 1;
	}
}
