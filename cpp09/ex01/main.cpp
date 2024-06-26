#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Error. Wrong usage." << std::endl;
        return 1;
    }
    
    // string str = argv[1];
    std::istringstream iss(argv[1]);
    cout << RPN::execute_expression(iss) << std::endl;
    return 0;
}