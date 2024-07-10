#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN {
    private:
        std::stack<long> m_operands;

    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        static double execute_expression(std::istringstream& expression);
};

#endif