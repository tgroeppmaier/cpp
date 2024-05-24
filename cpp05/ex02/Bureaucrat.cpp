#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;

// Exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Bureaucrat::AFormAlreadySigned::what() const throw() {
    return "AForm is already signed";
}

const char* Bureaucrat::NegativeNumberException::what() const throw() {
    return "Negative number passed";
}

// Constructors

Bureaucrat::Bureaucrat(const string& name)
    : m_name(name) {
    cout << "Bureaucrat default constructor called for " << m_name << '\n';
}

Bureaucrat::Bureaucrat(const string& name, int grade)
    : m_name (name),
      m_grade (grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } 
    if (grade > 150) {
        throw GradeTooLowException();
    }
    cout << "Bureaucrat constructor called for " << m_name << " with grade " << m_grade << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : m_name (other.m_name),
      m_grade (other.m_grade) {
    cout << "Bureaucrat copy constructor called for " << m_name << " with grade " << m_grade << '\n';
}

Bureaucrat::~Bureaucrat() {
    cout << "Bureaucrat default destructor called for " << m_name << '\n';
}

// Operator overload

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other){
        m_grade = other.m_grade;
    }
    return *this;
}

// Member Functions

const string& Bureaucrat::getName() const{
    return m_name;
}

int Bureaucrat::getGrade() const{
    return m_grade;
}


void Bureaucrat::incGrade(int num){
    if (num < 0) {
        throw NegativeNumberException();
    }
    else if (m_grade - num < 1) {
        throw GradeTooHighException();
    }
    m_grade -= num;
}

void Bureaucrat::decGrade(int num){
    if (num < 0) {
        throw NegativeNumberException();
    }
    else if (m_grade + num > 150) {
        throw GradeTooLowException();
    }
    m_grade += num;
}

void Bureaucrat::signAForm(AForm& form){
    form.beSigned(*this);
    cout << m_name << " signed " << form.getName() << '\n';
}

void Bureaucrat::executeForm(AForm const & form){
    try {
        form.execute(*this);
        cout << m_name << " executed " << form.getName() << '\n';
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cerr << e.what() << " for " << form.getName() <<  '\n';
    }
    catch (const AForm::FormNotSignedException& e) {
        std::cerr << e.what() << '\n';
    }
}

