#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

using std::cout;

void ExecuteFormWithException(void (AForm::*func)(const Bureaucrat&) const, Bureaucrat& bureaucrat, AForm& form) {
    try {
        (form.*func)(bureaucrat);
    }
    catch (const AForm::FormNotSignedException& e) {
        std::cerr << e.what() << '\n';
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }
}

void beSignedWithException(AForm& form, const Bureaucrat& bureaucrat) {
    try {
        form.beSigned(bureaucrat);
    }
    catch (const AForm::FormAlreadySigned& e) {
        std::cerr << e.what() << '\n';
    }
    catch (const AForm::GradeTooLowException& e) {
        std::cerr << e.what() << '\n';
    }

}

int main(){
    Bureaucrat cog1("Karl", 100);
    ShrubberyCreationForm formS("home");
    RobotomyRequestForm formR("Teacher");
    PresidentialPardonForm formP("Student");

    cog1.signAForm(formS);
    beSignedWithException(formS, cog1);
    cog1.signAForm(formS);
    cog1.signAForm(formR);
    cog1.signAForm(formP);
    ExecuteFormWithException(&AForm::execute, cog1, formP);
    cog1.executeForm(formS);
    cog1.executeForm(formR);
    cog1.executeForm(formP);

    Bureaucrat boss("Boss", 1);
    boss.signAForm(formR);
    boss.signAForm(formP);
    boss.executeForm(formR);
    boss.executeForm(formP);

    return 0;
}