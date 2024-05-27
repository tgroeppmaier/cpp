#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

using std::cout;

void signFormWithExceptionHandling(void (Bureaucrat::*func)(Form&), Bureaucrat& bureaucrat, Form& form){
    try {
        (bureaucrat.*func)(form);
    }
    catch (const Form::FormAlreadySigned& e) {
        std::cerr << e.what() << '\n';
    }
    catch (const Form::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }
}

int main(){
    Bureaucrat cog1("Karl", 10);
    
    try {
        Form form_h("28h", 151, 1);
    }
    catch (const Form::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        Form form_l("28h", 0, 1);
    }    
    catch (const Form::GradeTooHighException& e) {
        std::cerr << e.what() << '\n';
    }

    Form form_a("28b", 10, 1);
    
    try {
        form_a.beSigned(cog1);
    }
    catch (const Form::FormAlreadySigned& e) {
        std::cerr << e.what() << '\n';

    }
    signFormWithExceptionHandling(&Bureaucrat::signForm, cog1, form_a);

    cout << "Name: " << form_a.getName() << '\n';
    cout << "Is Signed: " << (form_a.isSigned() ? "Yes" : "No") << '\n';
    cout << "Grade to Sign: " << form_a.getGradeSign() << '\n';
    cout << "Grade to Execute: " << form_a.getGradeExec() << '\n';

    cout << form_a << '\n';

    return 0;
}