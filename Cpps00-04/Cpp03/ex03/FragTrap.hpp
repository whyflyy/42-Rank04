/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:59:03 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/20 13:18:10 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static unsigned int const _fragHp;
		static unsigned int const _fragAd;
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