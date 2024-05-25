#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ctime>   // for time
#include <cstdlib> // for rand

// Constructors

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), m_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const string& target) 
    : AForm("RobotomyRequestForm", 72, 45), m_target(target) {}
    
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), m_target(other.m_target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Operator overload

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

// Member Functions

string RobotomyRequestForm::getTarget() const {
    return m_target;
}

void RobotomyRequestForm::setTarget(const string& target) {
    m_target = target;
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