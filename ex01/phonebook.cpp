#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

void	printRightAlignedColumn(const std::string text);
void	printContactList(Contact contact[8], int current_count);

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darketsSecret;
public:
	void setContact(std::string first, std::string last,
	std::string nick, std::string phone, std::string secret)
	{
		this->firstName = first;
		this->lastName = last;
		this->nickname = nick;
		this->phoneNumber = phone;
		this->darketsSecret = secret;
	}
	std::string get_first(){
		return firstName;
	}
	std::string get_last(){
		return lastName;
	}
	std::string get_nick(){
		return nickname;
	}
	std::string get_phone(){
		return phoneNumber;
	}
	std::string get_secret(){
		return darketsSecret;
	}

};

class PhoneBook
{
	private:
		Contact contact[8];
		int currentCount;

	public:
		void add()
		{
			std::string first, last, nickname, phone, secret;

			std::cout << "Enter First Name: ";
			std::getline(std::cin, first);
			std::cout << "Enter Last Name: ";
			std::getline(std::cin, last);
			std::cout << "Enter Nickame: ";
			std::getline(std::cin, nickname);
			std::cout << "Enter Phone Number: ";
			std::getline(std::cin, phone);
			std::cout << "Enter Darkest Secret: ";
			std::getline(std::cin, secret);
			if (currentCount < 8)
			{
				contact[currentCount].setContact(first, last, nickname, phone, secret);
				currentCount++;
			}
			else
				contact[currentCount].setContact(first, last, nickname, phone, secret);
			std::cout << "Contact added successfully!\n";
		}
		void search()
		{
			Contact		person;
			std::string	input;
			int			index;

			printContactList(contact, currentCount);
			std::cout << "Enter The Index You Want to Search: ";
			std::getline(std::cin, input);
			if (input.size() == 1 && input[0] >= '1' && input[0] <= '8')
			{
				index = input[0] - '0' - 1;
				if (index > currentCount)
					std::cout << "Contact not saved yet" << std::endl;
				else
				{
					std::cout << "First Name: " << contact[index].get_first() << std::endl;
					std::cout << "Last Name: " << contact[index].get_last() << std::endl;
					std::cout << "Nickname: " << contact[index].get_nick() << std::endl;
					std::cout << "Phone Number: " << contact[index].get_phone() << std::endl;
					std::cout << "Darkest Secret: " << contact[index].get_secret() << std::endl;
				}
			}
			else
				std::cout << "Index out of range." << std::endl;
		}
};

void	printRightAlignedColumn(const std::string text)
{
	std::string truncatedText = text;
	if (truncatedText.length() > 10)
		truncatedText = truncatedText.substr(0, 9) + ".";

	std::cout << std::setw(10) << std::right << truncatedText;
}

void	printContactList(Contact contact[8], int current_count)
{
	int	i;

	i = 0;
	while (i < current_count)
	{
		printRightAlignedColumn(std::string(1, i + 1));
		std::cout << "|";
		printRightAlignedColumn(contact[i].get_first());
		std::cout << "|";
		printRightAlignedColumn(contact[i].get_last());
		std::cout << "|";
		printRightAlignedColumn(contact[i].get_nick());
		std::cout << '\n';
		i++;
	}
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
		{
			std::cout << "Exiting the program.\n";
			break ;
		}

	}
	return (0);
}
