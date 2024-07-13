#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Error. Wrong usage." << std::endl;
        return 1;
    }
    
    std::istringstream inputStream(argv[1]);
    try {
        std::cout << RPN::execute_expression(inputStream) << std::endl;
    } 
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}