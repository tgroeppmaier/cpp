#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
    private:
        unsigned int m_N;
        std::vector<int> m_nums;

    public:
        // Constructors
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();

        // Operator overload
        Span& operator=(const Span& other);

        // Member functions
        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
        void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);

        // Optional
        void printRange() const;
};
#endif