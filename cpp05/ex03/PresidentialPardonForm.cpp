#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Constructors 

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5), m_target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const string& target) 
    : AForm("PresidentialPardonForm", 25, 5), m_target(target) {}
    
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), m_target(other.m_target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Operator overload

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

// Member Functions

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << "\n";
}

string PresidentialPardonForm::getTarget() const {
    return m_target;
}

void PresidentialPardonForm::setTarget(const string& target) {
    m_target = target;
}