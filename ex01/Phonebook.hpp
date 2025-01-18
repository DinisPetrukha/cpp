/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:40:41 by dpetrukh          #+#    #+#             */
/*   Updated: 2025/01/18 22:16:52 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int currentCount;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add();
		void search();
};

void	printRightAlignedColumn(const std::string text);
void	printContactList(Contact contact[8], int current_count);

#endif