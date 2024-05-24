#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), m_target("default") {}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const string& target) 
    : AForm("PresidentialPardonForm", 25, 5), m_target(target) {}
    
// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), m_target(other.m_target) {}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Getter for m_target
string PresidentialPardonForm::getTarget() const {
    return m_target;
}

// Setter for m_target
void PresidentialPardonForm::setTarget(const string& target) {
    m_target = target;
}