#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery_form", 145, 137), m_target("default") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const string& target) 
    : AForm("Shrubbery_form", 145, 137), m_target(target) {}
    
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
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file((m_target + "_shrubbery").c_str());
    
    if (!file) {
        throw std::runtime_error("Unable to open file");
    }

    file << "  ^  \n / \\ \n/   \\ \n  ^  \n / \\ \n/   \\ \n";
    file.close();
}

// Getter for m_target
string ShrubberyCreationForm::getTarget() const {
    return m_target;
}

// Setter for m_target
void ShrubberyCreationForm::setTarget(const string& target) {
    m_target = target;
}