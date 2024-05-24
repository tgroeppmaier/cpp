#include "AForm.hpp"
#include <iostream>

using std::cout;

// exception classes

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Exception: Grade too low";
}

const char* AForm::NegativeNumberException::what() const throw() {
    return "Negative number passed";
}

const char* AForm::FormAlreadySigned::what() const throw() {
    return "Form is already signed";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}
        

// Constructors and destructor

AForm::AForm()
    : m_name ("Aform_default"), m_grade_sign (100), m_grade_exec (50), m_signed (false) {}

AForm::AForm(const string name, const int sign, const int exec) 
    : m_name (name), m_grade_sign (sign), m_grade_exec (exec), m_signed (false) {
        if (sign < 1 || exec < 1) {
        throw GradeTooHighException();
    } 
        else if (sign > 150 || exec > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other)
    : m_name (other.m_name), m_grade_sign (other.m_grade_sign), m_grade_exec (other.m_grade_exec), m_signed (false) {
}

AForm::~AForm(){
}

// operator overload

AForm& AForm::operator=(const AForm& other){
    if (this != &other) {
        m_signed = other.m_signed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
    os << "Name: " << obj.getName() 
       << ", Signed: " << (obj.isSigned() ? "Yes" : "No") 
       << ", Grade to Sign: " << obj.getGradeSign() 
       << ", Grade to Execute: " << obj.getGradeExec();
    return os;
}

// getters and setters

const string& AForm::getName() const {
    return m_name;
}

bool AForm::isSigned() const {
    return m_signed;
}

int AForm::getGradeSign() const {
    return m_grade_sign;
}

int AForm::getGradeExec() const {
    return m_grade_exec;
}

// member functions

void AForm::beSigned(Bureaucrat& signer){
    if (isSigned()) {
        throw FormAlreadySigned();
    }
    if (signer.getGrade() > m_grade_sign) {
        throw GradeTooLowException();
    }
    m_signed = true;
}

