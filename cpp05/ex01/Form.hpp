#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

using std::string;

class Bureaucrat;

class Form {
    private:
        const string m_name;
        const int m_grade_sign;
        const int m_grade_exec;
        bool m_signed;

    public:    
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };

        class FormAlreadySigned : public std::exception {
        public:
            const char* what() const throw();
        };

        class NegativeNumberException : public std::exception {
        public:
            const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw();
        };
        
        Form();
        Form(const string name, const int sign, const int exec);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        const string& getName() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;

        void beSigned(const Bureaucrat& signer);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif