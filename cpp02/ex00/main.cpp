#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a); // copy constructor
    Fixed c;

    c = b;  // copy assignment operator gets called on c
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    a.setRawBits(42);
    std::cout << a.getRawBits() << std::endl;
    return 0;
}