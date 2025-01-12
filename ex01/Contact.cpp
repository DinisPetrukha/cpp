/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:57:56 by dpetrukh          #+#    #+#             */
/*   Updated: 2025/01/09 21:12:03 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setContact(std::string first, std::string last,
		std::string nick, std::string phone, std::string secret)
{
	this->firstName = first;
	this->lastName = last;
	this->nickname = nick;
	this->phoneNumber = phone;
	this->darketsSecret = secret;
}

std::string Contact::get_first()
{
		return firstName;
}

std::string Contact::get_last()
{
	return lastName;
}

std::string Contact::get_nick()
{
	return nickname;
}
std::string Contact::get_phone()
{
	return phoneNumber;
}
std::string Contact::get_secret(){
	return darketsSecret;
}