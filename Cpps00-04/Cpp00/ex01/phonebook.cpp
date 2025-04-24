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

int	Phonebook::getNumEntries()
{
	return (this->_num_entries);
}

int	search_oldest_entry(Contact contacts[MAX_CONTACTS])
{
	int	oldest;

	oldest = 0;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i].getCreated() < contacts[oldest].getCreated())
			oldest = i;
	}
	return (oldest);
}

void    Phonebook::addContact(std::string Name, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string Secret)
{
	if (_num_entries < MAX_CONTACTS)
	{
		contacts[_num_entries] = Contact(Name, LastName, Nickname, PhoneNumber, Secret);
		_num_entries++;
	}
	else
		contacts[search_oldest_entry(contacts)] = Contact(Name, LastName, Nickname, PhoneNumber, Secret);
}
