#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
    private:
        std::vector<int> m_nums;
        unsigned int m_N;

    public:
        Span(); // Initializes m_nums to size 10
        Span(unsigned int N); // Initializes m_nums to size N
        Span(const Span& other); // Copy constructor
        ~Span();

        // Operator overload
        Span& operator=(const Span& other);

        // Member functions
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
};
#endif