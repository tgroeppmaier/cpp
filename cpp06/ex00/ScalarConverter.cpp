#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <limits>
#include <iostream>
#include <iomanip>

void convertToChar(double d) {
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || d != d)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void convertToInt(double d) {
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || d != d)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void convertToFloat(double d) {
    if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity()) {
        if (d > 0)
            std::cout << "float: inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    } 
    else if (d != d) {
        std::cout << "float: nanf" << std::endl;
    } 
    else {
        std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    }
}

void convertToDouble(double d) {
    if (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity()) {
        if (d > 0)
            std::cout << "double: inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    } 
    else if (d != d) {
        std::cout << "double: nan" << std::endl;
    } 
    else {
        std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << d << std::endl;
    }
}

ScalarConverter::ScalarConverter() {
}

void ScalarConverter::convert(std::string& str) {
    char* end;
    double d;

    if (str.length() == 1 && !isdigit(str[0])) {
        d = static_cast<double>(str[0]);
    } 
    else {
        d = std::strtod(str.c_str(), &end);
        if (end == str.c_str()) {   // means no conversion happened
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    convertToChar(d);
    convertToInt(d);
    convertToFloat(d);
    convertToDouble(d);
}