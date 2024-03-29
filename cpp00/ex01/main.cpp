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

/* Function to fill the PhoneBook */

// void FillBook(PhoneBook *book) {
// 	std::string firstNames[8] = {"John", "Jane", "Bob", "Alice", "Charlie", "Megan", "David", "Emma"};
// 	std::string lastNames[8] = {"Doe", "Smith", "Johnson", "Brown", "Davis", "Miller", "Wilson", "Moore"};
// 	std::string nicknames[8] = {"Johnny", "Janie", "Bobby", "Ali", "Char", "Meg", "Dave", "Em"};
// 	std::string phoneNumbers[8] = {"123", "456", "789", "012", "345", "678", "", "234"};
// 	std::string secrets[8] = {"secret1", "secret2", "secret3", "secret4", "secret5", "secret6", "secret7", "secret8"};

// 	for (int i = 0; i < 8; i++) {
// 		book->AddContact(firstNames[i], lastNames[i], nicknames[i], phoneNumbers[i], secrets[i]);
// 	}
// }	

// create a PhoneBook object, and then enter a loop that will prompt the user for a command.
// The command can be ADD, SEARCH, or EXIT.

int main()
{
	PhoneBook		book;
	std::string		line;

	std::cout << "Welcome to your crappy phone book software\n";
	// FillBook(&book);
	while(true)
	{
		std::cout << "Enter command \nADD SEARCH or EXIT\n";
		std::getline(std::cin, line);
		if(line == "ADD")
			AddContact(&book);
		else if(line == "SEARCH")
		{
			book.Search();
		}
		else if(line == "EXIT")
			break;
		else
			std::cout << "Invalid command\nPlease repeat\n";
	}
	std::cout << "Goodbye. All data has been erased\n";
	return(0);
}
