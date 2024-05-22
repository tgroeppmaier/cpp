#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include <iostream>

using std::cout;


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
    else if (grade > 150) {
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
    cout << "Bureaucrat default deconstructor called for " << m_name << '\n';
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if(this != &other){
        this->m_grade = other.m_grade;
    }
    return *this;

}

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

void Bureaucrat::signForm(Form& form){
    if(m_grade <= form.getGradeSign()){
        form.beSigned(*this);
        cout << m_name << " signed " << form.getName() << '\n';
    }
    else
        cout << m_name << " couldn't sign " << form.getName() << " because Grade too low\n";

}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}
