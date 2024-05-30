#include "ScalarConverter.hpp"

using std::string;
using std::cout;

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         cout << "Error. Usage: " << argv[0] << " <literal>" << '\n';
//         return 1;
//     }
    
//     string str = argv[1];
    
//     ScalarConverter::convert(str);
//     return 0;
// }

#include <iostream>
#include <sstream> // for std::stringstream
#include <string>

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        // On some operating systems, argv[0] can end up as an empty string instead of the program's name.
        // We'll conditionalize our response on whether argv[0] is empty or not.
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number>" << '\n';
        else
            std::cout << "Usage: <program name> <number>" << '\n';

        return 1;
    }

    std::stringstream convert; // set up a stringstream variable named convert
    convert << argv[1]; // insert the input from argv[1] into the stringstream

    int myint = 0;
    if (!(convert >> myint)) // do the conversion
        myint = 0; // if conversion fails, set myint to a default value

    std::cout << "Got integer: " << myint << '\n';

    return 0;
}