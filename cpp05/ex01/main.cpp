#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

using std::cout;

int main(){
    // try {
    //     Bureaucrat cog1("Karl", 200);
    // }
    // catch (Bureaucrat::GradeTooHighException& e) {
    //     std::cerr << "GradeTooHighException: " << e.what() << '\n';
    // }
    // catch (Bureaucrat::GradeTooLowException& e) {
    //     std::cerr << "GradeTooLowException: " << e.what() << '\n';
    // }
    
    // try {
    //     Bureaucrat cog1("Karl", -10);
    // }
    // catch (Bureaucrat::GradeTooHighException& e) {
    //     std::cerr << "GradeTooHighException: " << e.what() << '\n';
    // }
    // catch (Bureaucrat::GradeTooLowException& e) {
    //     std::cerr << "GradeTooLowException: " << e.what() << '\n';
    // }

    Bureaucrat cog1("Karl", 10);
    
    // try { cog1.decGrade(141);
    // }
    // catch (Bureaucrat::GradeTooHighException& e) {
    //     std::cerr << "GradeTooHighException: " << e.what() << '\n';
    // }
    // catch (Bureaucrat::GradeTooLowException& e) {
    //     std::cerr << "GradeTooLowException: " << e.what() << '\n';
    // }

    // try { cog1.incGrade(-10);
    // }
    // catch(const NegativeNumberException& e) {
    //     std::cerr << "NegativeNumberException: " << e.what() << '\n';
    // }
    // catch (const GradeTooHighException& e) {
    //     std::cerr << "GradeTooHighException: " << e.what() << '\n';
    // }
    // catch (const GradeTooLowException& e) {
    //     std::cerr << "GradeTooLowException: " << e.what() << '\n';
    // }

    // cout << cog1 << '\n';

    Form form_a("28b", 1, 1);
    // form_a.beSigned(cog1);
    cog1.signForm(form_a);


    return 0;
}