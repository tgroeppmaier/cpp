#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int num;
    std::string text;

    // Initializing to avoid garbage values
    Data() : num(0), text("") {};
};

#endif