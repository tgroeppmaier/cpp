#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&) = delete;
        ScalarConverter& operator=(const ScalarConverter&) = delete;
        
        static void convertToChar(double d);
        static void convertToInt(double d);
        static void convertToFloat(double d);
        static void convertToDouble(double d);

    public:
        static void convert(std::string& str);
};

#endif