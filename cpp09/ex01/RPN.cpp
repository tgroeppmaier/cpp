#include "RPN.hpp"
#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

RPN::RPN() : m_operands() {}

RPN::RPN(const RPN& other) : m_operands(other.m_operands) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->m_operands = other.m_operands;
    }
    return *this;
}

bool isNumber(const std::string& token) {
    if (token.empty()) {
        return false;
    }
    for (std::string::const_iterator it = token.begin(); it != token.end(); ++it) {
        if (!std::isdigit(static_cast<unsigned char>(*it))) {
            return false;
        }
    }
    return true;
}

bool isOperator(const std::string& token) {
    return token.length() == 1 && std::string("+-*/").find(token) != std::string::npos;
}

long calculate(std::stack<long>& operands, const std::string& token) {    
    if (operands.size() < 2) 
        throw std::runtime_error("Insufficient operands for operation.");

    long num2 = operands.top();
    operands.pop();
    long num1 = operands.top();
    operands.pop();

    switch (token[0]) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 == 0) {
                throw std::runtime_error("Division by zero");
            }
            return num1 / num2;
        default: throw std::runtime_error("Unsupported operation");
    }
}

long RPN::execute_expression(std::istringstream& expression) {
    std::stack<long> operands;
    std::string token;

    while (expression >> token) {
        if (isNumber(token)) {
            char* end;
            long num = std::strtol(token.c_str(), &end, 10);
            if (*end == 0) {
                operands.push(num);
            } else {
                throw std::runtime_error("Invalid number");
            }
        } 
        else if (isOperator(token)) {
            operands.push(calculate(operands, token));
        } 
        else {
            throw std::runtime_error("Invalid input");
        }
    }

    if (operands.empty()) 
        throw std::runtime_error("No operands in expression.");
    if (operands.size() != 1) 
        throw std::runtime_error("More than one number left in stack.");
    return operands.top();
}