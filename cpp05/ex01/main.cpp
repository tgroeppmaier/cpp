#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

using std::cout;

void IncDecWithExceptionHandling(void (Bureaucrat::*func)(int), Bureaucrat& bureaucrat, int num) {
    try {
        (bureaucrat.*func)(num);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "GradeTooHighException: " << e.what() << '\n';
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "GradeTooLowException: " << e.what() << '\n';
    } catch (const Bureaucrat::NegativeNumberException& e) {
        std::cerr << "NegativeNumberException: " << e.what() << '\n';
    }
}

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
    
    Form form_a("28b", 1, 1);
    // form_a.beSigned(cog1);
    // cog1.signForm(form_a);
    signFormWithExceptionHandling(&Bureaucrat::signForm, cog1, form_a);

    IncDecWithExceptionHandling(&Bureaucrat::decGrade, cog1, 200);
    // executeWithExceptionHandling(&Bureaucrat::incGrade, cog1, 1);
    return 0;
}