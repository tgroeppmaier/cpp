#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

void signAFormWithExceptionHandling(void (Bureaucrat::*func)(AForm&), Bureaucrat& bureaucrat, AForm& form){
    try {
        (bureaucrat.*func)(form);
    }
    catch (const AForm::FormAlreadySigned& e) {
        std::cerr << e.what() << '\n';
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }
}

int main(){
    Bureaucrat cog1("Karl", 10);
    ShrubberyCreationForm form1("home");
    RobotomyRequestForm formR("Teacher");
    PresidentialPardonForm formP("Student");

    cog1.signAForm(form1);
    cog1.signAForm(formR);
    cog1.signAForm(formP);
    // cog1.signAForm(form1);
    // form1.execute(cog1);
    cog1.executeForm(form1);
    cog1.executeForm(formR);
    cog1.executeForm(formP);



    // AForm form_a("28b", 1, 1);
    // form_a.beSigned(cog1);
    // cog1.signAForm(form_a);
    // signAFormWithExceptionHandling(&Bureaucrat::signAForm, cog1, form_a);

    // IncDecWithExceptionHandling(&Bureaucrat::decGrade, cog1, 200);
    // executeWithExceptionHandling(&Bureaucrat::incGrade, cog1, 1);
    return 0;
}