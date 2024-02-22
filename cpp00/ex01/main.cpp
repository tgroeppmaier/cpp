#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void AddContact(PhoneBook *book)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string secret;

	do {
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
	} while (first_name.empty());

	do {
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
	} while (last_name.empty());

	do {
		std::cout << "Enter nick name: ";
		std::getline(std::cin, nick_name);
	} while (nick_name.empty());

	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phone_number);
	} while (phone_number.empty());

	do {
		std::cout << "Enter secret: ";
		std::getline(std::cin, secret);
	} while (secret.empty());

	book->AddContact(first_name, last_name, nick_name, phone_number, secret);
}

int main()
{
	PhoneBook		book;
	std::string		line;

	std::cout << "Welcome to your crappy phone book software" << '\n';
	while(1)
	{
		std::cout << "Enter command \nADD SEARCH or EXIT" << '\n';
		std::getline(std::cin, line);
		if(line == "ADD")
			AddContact(&book);
		else if(line == "SEARCH")
		{
			book.ShowContacts();
		}
		else if(line == "EXIT")
			break;
		else
			std::cout << "Invalid command\n Please repeat\n";
	}
	return(0);
}
