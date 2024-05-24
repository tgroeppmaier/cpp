#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib> // for rand

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), m_target("default") {}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const string& target) 
    : AForm("Robotomy_form", 72, 45), m_target(target) {}
    
// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), m_target(other.m_target) {}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw AForm::GradeTooLowException();
    }

    srand(time(0));
    bool success = rand() % 2;

    if (success) {
        std::cout << "Drilling noises... " << m_target << " has been robotomized successfully." << std::endl;
    } 
    else {
        std::cout << m_target << " robotomization failed." << std::endl;
    }
}

// Getter for m_target
string RobotomyRequestForm::getTarget() const {
    return m_target;
}

// Setter for m_target
void RobotomyRequestForm::setTarget(const string& target) {
    m_target = target;
}