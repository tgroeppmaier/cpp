#include <cstdlib>
#include <cctype>
#include <limits>
#include <iostream>
#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& str) {
        char* end;
        double d = std::strtod(str.c_str(), &end);

        if (end == str.c_str()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        } else {
            // Convert to char
            if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || d != d)
                std::cout << "char: impossible" << std::endl;
            else if (std::isprint(static_cast<char>(d)))
                std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;

            // Convert to int
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || d != d)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(d) << std::endl;

            // Convert to float
            if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
                std::cout << "float: impossible" << std::endl;
            else if (d != d)
                std::cout << "float: nanf" << std::endl;
            else
                std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

            // Convert to double
            if (d != d)
                std::cout << "double: nan" << std::endl;
            else
                std::cout << "double: " << d << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}