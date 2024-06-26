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
        // long result;
        stack<long> m_operands;

    public:
        RPN();
        ~RPN();

        static long execute_expression(std::istringstream& expression);


};



#endif