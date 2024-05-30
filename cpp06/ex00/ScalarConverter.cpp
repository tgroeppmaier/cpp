#include "ScalarConverter.hpp"
#include <stdlib.h>

using std::cout;

void ScalarConverter::convert(std::string& str) {
    int num = atoi(str.c_str());
    cout << "int: ";
    if (num == 0) {
        cout << "no number\n";
    }
    if (num == -1) {
        cout << "out of bounds\n";
    }
    else {
        cout << num << '\n';
    }
    

}