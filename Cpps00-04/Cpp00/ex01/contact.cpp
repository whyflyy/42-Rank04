/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:01:57 by jcavadas          #+#    #+#             */
/*   Updated: 2025/03/02 23:01:57 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


Contact::Contact()
{
	//TODO tem de ter alguma aqui dentro?
}

Contact::Contact(std::string Name, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string Secret)
{
	_Name = Name;
	_LastName = LastName;
	_Nickname = Nickname;
	_PhoneNumber = PhoneNumber;
	_Secret = Secret;
	time(&_Created);
}

Contact::~Contact(){
}

//Fetchers
std::string		Contact::getName() const
{
	return (_Name);
}

std::string		Contact::getLastName() const
{
	return (_LastName);
}

std::string		Contact::getNickName() const
{
	return (_Nickname);
}

std::string		Contact::getPhoneNumber() const
{
	return (_PhoneNumber);
}

std::string		Contact::getSecret() const
{
	return (_Secret);
}

time_t			Contact::getCreated() const
{
	return (_Created);
}


