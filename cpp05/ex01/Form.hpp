#ifndef FORM_HPP
#define FORM_HPP

#include "Exceptions.hpp"
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
        Form(const string name, const int sign, const int exec);
        Form(const Form& other);
        ~Form();

        const string& getName() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;

        void beSigned(Bureaucrat& signer);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif