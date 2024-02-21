#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first_name,
				 std::string last_name, 
				 std::string nick_name,
				 std::string phone_number,
				 std::string secret) :
	first_name_(first_name),
	last_name_(last_name),
	nick_name_(nick_name),
	phone_number_(phone_number),
	secret_(secret)
{
}

Contact::~Contact()
{

}

void Contact::SetContact(std::string first_name,
						 std::string last_name, 
						 std::string nick_name,
						 std::string phone_number,
						 std::string secret)
{
	first_name_ = first_name;
	last_name_ = last_name;
	nick_name_ = nick_name;
	phone_number_ = phone_number;
	secret_ = secret;
}

std::string Contact::GetFirstName() const
{
	return first_name_;
}

std::string Contact::GetLastName() const
{
	return last_name_;
}

std::string Contact::GetNickName() const
{
	return nick_name_;
}

std::string Contact::GetPhoneNumber() const
{
	return phone_number_;
}

std::string Contact::GetSecret() const
{
	return secret_;
}
