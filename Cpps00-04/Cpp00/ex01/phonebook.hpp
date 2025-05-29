/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:41:23 by jcavadas          #+#    #+#             */
/*   Updated: 2025/03/02 22:41:23 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "contact.hpp"

# define MAX_CONTACTS 8

class Phonebook
{
	private:
		int	_num_entries;
	public:
		Contact contacts[MAX_CONTACTS];
		//Constructors
		Phonebook();
		~Phonebook();

		//Member funtions
		void	addContact(std::string Name, std::string LastName, std::string Nickname, 
					std::string PhoneNumber, std::string Secret);
		int		getNumEntries();
};

int	search_oldest_entry(Contact contacts[MAX_CONTACTS]);

#endif
