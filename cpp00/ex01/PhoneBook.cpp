#include <iostream>
#include <string>
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