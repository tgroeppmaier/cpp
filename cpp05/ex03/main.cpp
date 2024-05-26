#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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
    AForm *scf, *rrf, *ppf, *nonexistent;
    Bureaucrat cog1("scrub", 100);
    Bureaucrat cog2("manager", 10);
    Bureaucrat cog3("boss", 1);
    Intern rando;
    scf = rando.makeForm("shrubbery creation", "teacher");
    rrf = rando.makeForm("robotomy request", "teacher");
    ppf = rando.makeForm("presidential pardon", "teacher");

    cog1.signAForm(*scf);
    cog1.executeForm(*scf);

    cog1.signAForm(*rrf);
    cog1.signAForm(*ppf);

    cog2.signAForm(*rrf);
    cog2.signAForm(*ppf);
    cog2.executeForm(*rrf);
    cog2.executeForm(*ppf);

    cog3.executeForm(*ppf);
    try {
        nonexistent = rando.makeForm("nonexistent", "teacher");
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception! " << e.what() << std::endl;
    }
    (void)nonexistent;

    delete scf;
    delete rrf;
    delete ppf;  

    return 0;
}