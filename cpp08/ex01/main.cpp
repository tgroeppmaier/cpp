#include "Span.hpp"
#include <iostream>
#include <numeric>

void subject() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void extra() {
    Span sp_short(1);
    try {
        std::cout << sp_short.shortestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << sp_short.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    Span sp(50000);
    std::vector<int> numbers(50001);

    int startValue = 0;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        *it = startValue++;
    }
    try {
        sp.addRange(numbers.begin(), numbers.end());
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    // sp.printRange();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main() {
    subject();
    // extra();
    return 0;
}
