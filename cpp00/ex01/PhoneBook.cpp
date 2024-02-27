#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::AddContact(std::string first_name,
	  				std::string last_name, 
					std::string nick_name,
					std::string phone_number,
					std::string secret)
{
	contacts[index].SetContact(first_name, last_name, nick_name, phone_number, secret);
    index = (index + 1) % 8;
}

void PhoneBook::ShowContacts() const
{
	for(int i = 0; i < 8; i++)
	{
		contacts[i].PrintContact();
	}
}

void PhoneBook::Search() const
{
	std::cout << "||     index|first name| last name|  nickname||" << std::endl;

	for(int i = 0; i < 8; i++) {
		std::cout << "||" << std::setw(10) << i;

		std::string firstName = contacts[i].GetFirstName();
		std::string lastName = contacts[i].GetLastName();
		std::string nickName = contacts[i].GetNickName();

		if (firstName.length() > 10) {
			firstName = firstName.substr(0, 9) + ".";
		}
		if (lastName.length() > 10) {
			lastName = lastName.substr(0, 9) + ".";
		}
		if (nickName.length() > 10) {
			nickName = nickName.substr(0, 9) + ".";
		}

		std::cout << "|" << std::setw(10) << firstName;
		std::cout << "|" << std::setw(10) << lastName;
		std::cout << "|" << std::setw(10) << nickName;
		std::cout << "||" << std::endl;
	}

	int index;
	
	do {
		std::cout << "Enter the index of the contact you want to view: ";
		std::cin >> index;
		if (index >= 0 && index < 9) {
			std::cout << "Contact information for index " << index << ":\n";
			std::cout << "First name: " << contacts[index].GetFirstName() << "\n";
			std::cout << "Last name: " << contacts[index].GetLastName() << "\n";
			std::cout << "Nickname: " << contacts[index].GetNickName() << "\n";
			std::cout << "Telephone number: " << contacts[index].GetPhoneNumber() << "\n";
			std::cout << "Secret: " << contacts[index].GetSecret() << "\n";
			break;
		}
		else {
			std::cout << "Invalid index. Please enter a number between 0 and 7.\n";
		}
	} while (true);

    

}