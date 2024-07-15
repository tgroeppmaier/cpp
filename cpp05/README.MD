# Cpp 05

- [Cpp 05](#cpp-05)
  - [To know](#to-know)
    - [Exceptions](#exceptions)
  - [ex00](#ex00)
  - [ex01](#ex01)
  - [ex02](#ex02)
    - [Task](#task)
    - [Things to consider](#things-to-consider)
  - [ex03](#ex03)


This Project is about exceptions

[Instructions](./cpp05.pdf)

## To know

### Exceptions

Instead of the program crashing when an error occurs, we can "throw" an exception. This passes the error up to a higher level of the program where it can be "caught". Once caught, we can define how the program should respond to the error, allowing the program to continue running or fail gracefully. This is a key part of error handling in many programming languages.

## ex00

To throw a custom exception, we have to declare it first.
Because of the instructions, we declare the exception classes inside Bureaucrat class.  
This new class inherits the what() method from std::exception, which we then override in the function definition.

```cpp
from Bureaucrat.hpp

class Bureaucrat {
    public:
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };
}
```

```cpp
from Bureaucrat.cpp

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}
```

## ex01

Here we implement a Form class, which also throws an exception, when the grade is too low or high. To the Bureucrat class we add a signForm Function, which signs a given Form and prints a Statement, if succesful or not.

## ex02

### Task

- Rename the `Form` class to `AForm` and make it an abstract class.
- Keep the form’s attributes private and in the base class.
- Add the following concrete classes:
    - **ShrubberyCreationForm**: Required grades: sign 145, exec 137. This form creates a file `<target>_shrubbery` in the working directory and writes ASCII trees inside it.
    - **RobotomyRequestForm**: Required grades: sign 72, exec 45. This form makes drilling noises and informs that `<target>` has been robotomized successfully 50% of the time. Otherwise, it informs that the robotomy failed.
    - **PresidentialPardonForm**: Required grades: sign 25, exec 5. This form informs that `<target>` has been pardoned by Zaphod Beeblebrox.
- All of these classes take only one parameter in their constructor: the target of the form.
- Add the `execute(Bureaucrat const & executor) const` member function to the base form and implement a function to execute the form’s action of the concrete classes.
- Check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. If not, throw an appropriate exception.
- Add the `executeForm(AForm const & form)` member function to the `Bureaucrat`. It must attempt to execute the form. If it’s successful, print something like: `<bureaucrat> executed <form>`. If not, print an explicit error message.
- Implement and turn in some tests to ensure everything works as expected.
- Turn in the following files: `Makefile`, `main.cpp`, `Bureaucrat.[{h, hpp},cpp]`, `AForm.[{h, hpp},cpp]`, `ShrubberyCreationForm.[{h, hpp},cpp]`, `RobotomyRequestForm.[{h, hpp},cpp]`, `PresidentialPardonForm.[{h, hpp},cpp]`.

Form Class is to be renamed into AForm and made an abstract class. We add three Forms that inherit from AForm. All with different grade required to sign and execute and a unique execute method which we implement as pure virtual. Again checking the grades and throwing exceptions. To the Bureaucrat we add the executeForm method. I implemented this by calling the form.execute and catch the errors there.

### Things to consider

- `Destructor` of `AForm` needs to be virtual now
- We have two methods to sign and two to execute a Form. One in `Bureaucrat` and one in `Aform`
- 
## ex03

