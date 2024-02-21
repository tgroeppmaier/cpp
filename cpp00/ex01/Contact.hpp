#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
 public:
  Contact();
  Contact(std::string first_name,
	  std::string last_name, 
	  std::string nick_name,
	  std::string phone_number,
	  std::string secret);
  ~Contact();

  void SetContact(std::string first_name,
		  std::string last_name, 
		  std::string nick_name,
		  std::string phone_number,
		  std::string secret);
  std::string GetFirstName() const;
  std::string GetLastName() const;
  std::string GetNickName() const;
  std::string GetPhoneNumber() const;
  std::string GetSecret() const;

 private:
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string secret_;
};

#endif