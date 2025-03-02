/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:41:32 by jcavadas          #+#    #+#             */
/*   Updated: 2025/03/02 22:41:32 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	_num_entries = 0;
}

Phonebook::~Phonebook()
{
	
}

void    Phonebook::addContact(std::string Name, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string Secret)
{
	if (_num_entries < MAX_CONTACTS)
	{
		//contacts
		(void) Name;
		(void) LastName;
		(void) Nickname;
		(void) PhoneNumber;
		(void) Secret;

	}
}
