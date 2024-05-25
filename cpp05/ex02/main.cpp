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
    // beSignedWithException(formS, cog1);
    // cog1.signAForm(formS);
    cog1.signAForm(formR);
    cog1.signAForm(formP);
    ExecuteFormWithException(&AForm::execute, cog1, formP);
    // formP.execute(cog1);
    cog1.executeForm(formS);
    cog1.executeForm(formR);
    cog1.executeForm(formP);


    // IncDecWithExceptionHandling(&Bureaucrat::decGrade, cog1, 200);
    return 0;
}