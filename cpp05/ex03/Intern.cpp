#include "Intern.hpp"

Intern::Intern() {
    name_array[0] = "shrubbery creation";
    name_array[1] = "robotomy request";
    name_array[2] = "presidential pardon";

    functionArray[0] = &Intern::createShrubberyCreationForm;
    functionArray[1] = &Intern::createRobotomyRequestForm;
    functionArray[2] = &Intern::createPresidentialPardonForm;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const string& name, const string& target) {
    for (int i = 0; i < 3; i++) {
        if (name_array[i] == name) {
            return functionArray[i](target);
        }
    }
    return NULL;
}