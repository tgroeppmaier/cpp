#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;

class Bureaucrat::GradeTooHighException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too high";
    }
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
    const char* what() const throw() {
        return "Grade too low";
    }
};

class Bureaucrat::NegativeNumberException : public std::exception {
public:
    const char* what() const throw() {
        return "Negative number passed";
    }
};

class Bureaucrat::FormAlreadySigned : public std::exception {
public:
    const char* what() const throw() {
        return "Form is already signed";
    }
};

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
    cout << "Bureaucrat default destructor called for " << m_name << '\n';
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
    try {
        form.beSigned(*this);
        cout << m_name << " signed " << form.getName() << '\n';
    }
    catch (const GradeTooLowException& e) {
        cout << m_name << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
    }

    catch (const FormAlreadySigned& e) {
        cout << m_name << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

