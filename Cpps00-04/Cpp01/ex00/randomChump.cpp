/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:23:38 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/29 12:04:06 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Allocates on the stack, it's simple and gets cleaned up automatically when it goes out of scope
//Can only be used on the current function
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
