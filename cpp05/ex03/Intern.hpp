#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
private:
    std::string name_array[3];

    typedef AForm* (*FormCreator)(const std::string&);
    FormCreator functionArray[3];

    static AForm* createShrubberyCreationForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createPresidentialPardonForm(const std::string& target);

public:
    Intern();
    ~Intern();
    AForm* makeForm(const std::string& name, const std::string& target);
};

#endif