#ifndef FORM_HPP
#define FORM_HPP

#include <string>

using std::string;

class Form {
    private:
        const string m_name;
        bool m_signed;
        const unsigned int m_grade_sign;
        const unsigned int m_grade_exec;

    public:
        Form(const string name, const unsigned int sign, const unsigned int exec);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);
}


#endif