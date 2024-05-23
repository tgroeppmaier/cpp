#include "Form.hpp"
#include <iostream>

using std::cout;

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Form::NegativeNumberException::what() const throw() {
    return "Negative number passed";
}

const char* Form::FormAlreadySigned::what() const throw() {
    return "Form is already signed";
}

Form::Form(const string name, const int sign, const int exec) 
    : m_name (name), m_grade_sign (sign), m_grade_exec (exec), m_signed (false) {
        if (sign < 1 || exec < 1) {
        throw GradeTooHighException();
    } 
        else if (sign > 150 || exec > 150) {
        throw GradeTooLowException();
    }
    cout << "Form default constructor called\n";
}

Form::Form(const Form& other)
    : m_name (other.m_name), m_grade_sign (other.m_grade_sign), m_grade_exec (other.m_grade_exec), m_signed (false) {
    cout << "Form copy constructor called\n";       
}

Form::~Form(){
    cout << "Form default destructor called\n";       
}

Form& Form::operator=(const Form& other){
    if (this != &other) {
        m_signed = other.m_signed;
    }
    return *this;
}

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


void Form::beSigned(Bureaucrat& signer){
    if (isSigned()) {
        throw FormAlreadySigned();
    }
    if (signer.getGrade() > m_grade_sign) {
        throw GradeTooLowException();
    }
    m_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
    os << "Name: " << obj.getName() 
       << ", Signed: " << (obj.isSigned() ? "Yes" : "No") 
       << ", Grade to Sign: " << obj.getGradeSign() 
       << ", Grade to Execute: " << obj.getGradeExec();
    return os;
}
