#include "RPN.hpp"
#include <cctype> // For isdigit
#include <stdexcept>

RPN::RPN() {} 

RPN::~RPN() {} 

bool isNumber(const string& token) {
    if (token.empty()) return false;

    for (std::string::const_iterator it = token.begin(); it != token.end(); ++it) {
        if (!std::isdigit(static_cast<unsigned char>(*it))) return false;
    }

    return true;
}

bool isOperator(const string& token) {
    if (token.length() != 1 || (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'))
        return false;
    return true;
}

long calculate (stack<long>& operands, const string& token) {    
    if (operands.size() < 2) {
            throw std::runtime_error("Insufficient operands for operation.");
        }

    long num1 = operands.top();
    operands.pop();
    long num2 = operands.top();
    operands.pop();

    if (token[0] == '+') {
        return num1 + num2;
    }
    if (token[0] == '-') {
        return num1 - num2;
    }
    if (token[0] == '*') {
        return num1 * num2;
    }
    if (token[0] == '/') {
        if (num2 == 0)
            throw std::runtime_error("Division by zero");
        return num1 / num2;
    }
}

long RPN::execute_expression(std::istringstream& expression) {
    long result = 0;
    stack<long> operands;
    string token;
    double number;
    char *end;

    while(expression >> token) {
        if (isNumber(token)) {
            operands.push(strtod(token.c_str(), &end));
        }
        else if (isOperator(token)) {
            operands.push(calculate(operands, token));
        }
        else {
            cout << "Error. Invalid Input" << std::endl;
            return result;
        }
    }
    return operands.top();
}

