# Cpp 05

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

