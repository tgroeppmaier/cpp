#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
    private:
        std::vector<int> m_nums;
        unsigned int m_N;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();

        // Operator overload
        Span& operator=(const Span& other);

        // Member functions
        void addNumber(int num);
        void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
        void printRange();
        int shortestSpan();
        int longestSpan();
};
#endif