/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:59:03 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 12:34:19 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		/* data */
	public:
		//Orthodox Canonical form
		//Default Constructor
		FragTrap();
		//Constructor with name
		FragTrap(std::string Name);
		//Copy Constructor
		FragTrap(const FragTrap &copy);
		//Copy assignement operator overload
		FragTrap &operator=(const FragTrap &copy);
		//Destructor
		~FragTrap();

		//Member functions
		void	highFivesGuys(void);
};



#endif