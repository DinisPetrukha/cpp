/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:59:32 by dpetrukh          #+#    #+#             */
/*   Updated: 2025/01/11 19:15:44 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darketsSecret;

	public:
		Contact(void);
		~Contact(void);
		void setContact(std::string first, std::string last,
		std::string nick, std::string phone, std::string secret);
		std::string get_first();
		std::string get_last();
		std::string get_nick();
		std::string get_phone();
		std::string get_secret();
};

#endif
