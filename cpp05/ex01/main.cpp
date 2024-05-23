#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

using std::cout;

// void executeWithExceptionHandling(void (Bureaucrat::*func)(int), Bureaucrat& bureaucrat, int num) {
//     try {
//         (bureaucrat.*func)(num);
//     } catch (const Bureaucrat::GradeTooHighException& e) {
//         std::cerr << "GradeTooHighException: " << e.what() << '\n';
//     } catch (const Bureaucrat::GradeTooLowException& e) {
//         std::cerr << "GradeTooLowException: " << e.what() << '\n';
//     } catch(const Bureaucrat::NegativeNumberException& e) {
//         std::cerr << "NegativeNumberException: " << e.what() << '\n';
//     }
// }

int main(){
    Bureaucrat cog1("Karl", 10);
    
    Form form_a("28b", 10, 1);
    form_a.beSigned(cog1);
    cog1.signForm(form_a);

    // executeWithExceptionHandling(&Bureaucrat::decGrade, cog1, 1);
    // executeWithExceptionHandling(&Bureaucrat::incGrade, cog1, 1);
    return 0;
}