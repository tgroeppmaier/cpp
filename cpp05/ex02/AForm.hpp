#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

using std::string;

class Bureaucrat;

class AForm {
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
        
        AForm();
        AForm(const string name, const int sign, const int exec);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);

        const string& getName() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;

        void beSigned(const Bureaucrat& signer);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif