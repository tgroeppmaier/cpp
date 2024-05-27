#include "Form.hpp"
#include <iostream>

using std::cout;

// exception classes

const char* Form::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Exception: Grade too low";
}

const char* Form::NegativeNumberException::what() const throw() {
    return "Exception: Negative number passed";
}

const char* Form::FormAlreadySigned::what() const throw() {
    return "Exception: Form is already signed";
}

const char* Form::FormNotSignedException::what() const throw() {
    return "Exception: Form is not signed";
}
        
// Constructors and destructor

Form::Form()
    : m_name ("Form_default"), m_grade_sign (100), m_grade_exec (50), m_signed (false) {}

Form::Form(const string name, const int sign, const int exec) 
    : m_name (name), m_grade_sign (sign), m_grade_exec (exec), m_signed (false) {
        if (sign < 1 || exec < 1) {
        throw GradeTooHighException();
    } 
        else if (sign > 150 || exec > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other)
    : m_name (other.m_name), m_grade_sign (other.m_grade_sign), m_grade_exec (other.m_grade_exec), m_signed (false) {
}

Form::~Form(){
}

// operator overload

Form& Form::operator=(const Form& other){
    if (this != &other) {
        m_signed = other.m_signed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
    os << "Name: " << obj.getName() 
       << ", Signed: " << (obj.isSigned() ? "Yes" : "No") 
       << ", Grade to Sign: " << obj.getGradeSign() 
       << ", Grade to Execute: " << obj.getGradeExec();
    return os;
}

// member functions

const string& Form::getName() const {
    return m_name;
}

bool Form::isSigned() const {
    return m_signed;
}

int Form::getGradeSign() const {
    return m_grade_sign;
}

int Form::getGradeExec() const {
    return m_grade_exec;
}

void Form::beSigned(const Bureaucrat& signer){
    if (isSigned()) {
        throw FormAlreadySigned();
    }
    if (signer.getGrade() > m_grade_sign) {
        throw GradeTooLowException();
    }
    m_signed = true;
}
