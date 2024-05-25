#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Constructors

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), m_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), m_target(target) {}
    
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), m_target(other.m_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Operator overload

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

// Member functions

string ShrubberyCreationForm::getTarget() const {
    return m_target;
}

void ShrubberyCreationForm::setTarget(const string& target) {
    m_target = target;
}

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
