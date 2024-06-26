#include "Span.hpp"
#include <exception>
#include <iostream>
#include <stdexcept> // Include for std::out_of_range
#include <algorithm> // Include for std::sort
#include <limits>    // Include for std::numeric_limits

Span::Span() : m_N(10), m_nums() {}
Span::Span(unsigned int N) : m_N(N), m_nums() {}
Span::Span(const Span& other) : m_N(other.m_N), m_nums(other.m_nums) {}
Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        m_nums = other.m_nums;
        m_N = other.m_N;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (m_nums.size() == m_N) {
        throw std::out_of_range("Cannot add more numbers, Span is full.");
    }
    m_nums.push_back(num);
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = start; it != end; ++it) {
        if (m_nums.size() >= m_N) {
            throw std::out_of_range("Cannot add more numbers, Span is full.");
        }
        m_nums.push_back(*it);
    }
}

int Span::shortestSpan() const {
    if (m_nums.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted_nums = m_nums; // Copy the numbers to sort them
    std::sort(sorted_nums.begin(), sorted_nums.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted_nums.size(); ++i) {
        shortest = std::min(shortest, sorted_nums[i] - sorted_nums[i - 1]);
    }
    return shortest;
}

int Span::longestSpan() const {
    if (m_nums.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }

    std::vector<int>::const_iterator min = std::min_element(m_nums.begin(), m_nums.end());
    std::vector<int>::const_iterator max = std::max_element(m_nums.begin(), m_nums.end());
    return *max - *min;
}

void Span::printRange() const {
    for (std::vector<int>::const_iterator it = m_nums.begin(); it != m_nums.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

