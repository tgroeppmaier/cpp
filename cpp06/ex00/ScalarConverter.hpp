#include <string>
#include <iostream>

class ScalarConverter {
    private:
        ScalarConverter();

        static void convertToChar(double d);
        static void convertToInt(double d);
        static void convertToFloat(double d);
        static void convertToDouble(double d);

    public:
        static void convert(std::string& str);
};
