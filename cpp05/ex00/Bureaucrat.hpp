#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

class Form;

using std::string;

class Bureaucrat {
    private:
        const string m_name;
        int m_grade;

    public:
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };

        class AFormAlreadySigned : public std::exception {
        public:
            const char* what() const throw();
        };

        class NegativeNumberException : public std::exception {
        public:
            const char* what() const throw();
        };

        Bureaucrat();
        Bureaucrat(const string& name);
        Bureaucrat(const string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);
        
        const string& getName() const;
        int getGrade() const;
        void incGrade(int num);
        void decGrade(int num);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);


#endif