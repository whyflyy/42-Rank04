/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:02:03 by jcavadas          #+#    #+#             */
/*   Updated: 2025/03/02 23:02:03 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	_Name;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_Secret;
		time_t		_Created;
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nick_name,
				std::string phone_number, std::string darkest_secret);
		~Contact();

		//Fetch functions
		std::string		getName() const;
		std::string		getLastName() const;
		std::string		getNickName() const;
		std::string		getPhoneNumber() const;
		std::string		getSecret() const;
		time_t			getCreated() const;
};

#endif
