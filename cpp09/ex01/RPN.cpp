#include "RPN.hpp"
#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath>

RPN::RPN() : m_operands() {}

RPN::RPN(const RPN& other) : m_operands(other.m_operands) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->m_operands = other.m_operands;
    }
    return *this;
}

bool isNumber(const std::string& token, double& num) {
    if (token.empty()) {
        return false;
    }
    char* end;
    num = std::strtod(token.c_str(), &end); // Convert string to double
    // Check if conversion is successful and the number is within the specified range
    if (*end == 0 && num > -10 && num < 10) { 
        return true;
    }
    return false;
}

bool isOperator(const std::string& token) {
    return token.length() == 1 && std::string("+-*/").find(token) != std::string::npos;
}

double calculate(std::stack<double>& operands, const std::string& token) {
    double num2 = operands.top();
    operands.pop();
    double num1 = operands.top();
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

double RPN::execute_expression(std::istringstream& expression) {
    std::stack<double> operands;
    std::string token;

    while (expression >> token) {
        double num;
        if (isNumber(token, num)) {
            operands.push(num);
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