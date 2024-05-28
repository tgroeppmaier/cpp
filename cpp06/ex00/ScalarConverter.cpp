#include "ScalarConverter.hpp"
#include <stdlib.h>

void ScalarConverter::convert(std::string& str) {
    int num;
    
    try {
        num = atoi(str.c_str());
        // Use num...
    } catch (std::invalid_argument const &e) {
        // The string does not represent a valid integer
    } catch (std::out_of_range const &e) {
        // The integer represented by the string is out of the range of int
    }

    std::cout << num << '\n';
}