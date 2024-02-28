#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

class PhoneBook {
	public:
	 PhoneBook();
	 ~PhoneBook();

	void AddContact(std::string first_name,
	  				std::string last_name, 
					std::string nick_name,
					std::string phone_number,
					std::string secret);
	void Search() const;
	void ShowContacts() const;

	private:
	 Contact 	contacts[8];
	 int		index;
};

#endif