/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:22:48 by jcavadas          #+#    #+#             */
/*   Updated: 2025/05/29 11:41:59 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Allocates on the heap, and is more flexible but the memory needs to be managed manually
//Acessed using a pointer, and can be used out of the function
//Persists until explicitly deleted
Zombie* newZombie(std::string name)
{
    Zombie *zombie;

    zombie = new Zombie(name);
    return (zombie);
}
