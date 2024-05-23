#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Exceptions.hpp"
#include "Form.hpp"
#include <string>
#include <ostream>

class Form;

using std::string;

class Bureaucrat {
    private:
        const string m_name;
        int m_grade;

    public:
        Bureaucrat(const string& name);
        Bureaucrat(const string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);
        
        const string& getName() const;
        int getGrade() const;
        void incGrade(int num);
        void decGrade(int num);

        void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);


class GradeTooHighException : public std::exception {
    public:
    const char* what() const throw() {
        return "Grade too high";
    }
};

class GradeTooLowException : public std::exception {
    public:
    const char* what() const throw() {
        return "Grade too low";
    }
};

class NegativeNumberException : public std::exception {
    public:
    const char* what() const throw(){
        return "Negative number passed";
    }
};      
    
class FormAlreadySigned : public std::exception {
    public:
    const char* what() const throw(){
        return "Form is already signed";
    }
};      



#endif