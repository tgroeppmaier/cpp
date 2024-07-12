#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

using std::stack;
using std::string;
using std::cout;

class RPN {
    private:
        stack<long> m_operands;

    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        static long execute_expression(std::istringstream& expression);
};

#endif