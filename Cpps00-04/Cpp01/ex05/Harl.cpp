/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:35:31 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/09 16:49:41 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << MAGENTA << "[DEBUG] " << RESET << "Watch where the birds fly, they will lead us to land." << std::endl;
}

void	Harl::info(void)
{
	std::cout << BLUE << "[INFO] " << RESET << "Six hundred men, six hundred miles of open sea." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING] " << RESET << "This land confuses your mind." << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "[ERROR] " << RESET << "All I hear are screams, every time I dare to close my eyes." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*funcs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << CYAN << "[NOTHING] " << RESET << "Where am I?" << std::endl;
}
