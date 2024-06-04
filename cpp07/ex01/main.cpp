#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& value) {
    std::cout << value << ' ';
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    unsigned int intLen = sizeof(intArray) / sizeof(intArray[0]);

    iter(intArray, intLen, print<int>);

    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "from", "iter"};
    unsigned int strLen = sizeof(strArray) / sizeof(strArray[0]);

    iter(strArray, strLen, print<std::string>);
    std::cout << std::endl;

    return 0;
}