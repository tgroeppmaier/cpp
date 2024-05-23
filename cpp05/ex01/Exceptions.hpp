#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

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