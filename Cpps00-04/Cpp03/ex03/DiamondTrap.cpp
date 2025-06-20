/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:51:27 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 13:40:10 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << GREEN << "DiamondTrap Default constructor called" << RESET << std::endl;
	this->_Name = "default";
	this->ClapTrap::_Name = this->_Name + "_clap_name";
	this->_Hp = _fragHp;
	this->_Ep = _scavEp;
	this->_Ad = _fragAd;
}

//Named Constructor
DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), FragTrap(Name), ScavTrap(Name)
{
	std::cout << GREEN << "DiamondTrap Name constructor called" << RESET << std::endl;
	this->_Name = Name;
	this->_Hp = _fragHp;
	this->_Ep = _scavEp;
	this->_Ad = _fragAd;
}

//Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	std::cout << CYAN << "DiamondTrap Copy constructor called" << RESET << std::endl;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Ep = copy._Ep;
	this->_Ad = copy._Ad;
}

//Copy assignement operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << MAGENTA << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
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
DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap Default destructor called" << RESET << std::endl;
	
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hi, my name is: " << YELLOW << this->_Name << RESET << std::endl;
	std::cout << "But my real name is: " << YELLOW << ClapTrap::_Name << RESET << std::endl;
}
