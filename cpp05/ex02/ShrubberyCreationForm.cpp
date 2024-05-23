#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), m_target("") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm(), m_target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), m_target(other.m_target) {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

// execute method
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // Implementation goes here
}

// Getter for m_target
string ShrubberyCreationForm::getTarget() const {
    return m_target;
}

// Setter for m_target
void ShrubberyCreationForm::setTarget(const string& target) {
    m_target = target;
}