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
    Span sp(50000);
    std::vector<int> numbers(50000);
    try {
        std::iota(numbers.begin(), numbers.end(), 0);
        sp.addRange(numbers.begin(), numbers.end());
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    sp.printRange();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main() {
    subject();
    // extra();
    return 0;
}
