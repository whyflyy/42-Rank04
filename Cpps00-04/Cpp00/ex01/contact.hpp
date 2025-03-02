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
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	Name;
		std::string	LastName;
		std::string	Nickname;
		std::string	PhoneNumber;
		std::string	Secret;
	public:
		Contact();
		~Contact();

		//TODO funcao
		//TODO funcao

		//TODO fetch funcao

};

#endif