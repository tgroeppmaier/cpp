#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#define DB_PATH "data.csv"

int main(int argc, char* argv[]) {    
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange(DB_PATH);
    try {
        exchange.initializeDB();
        exchange.readInput(argv[1]);
        exchange.processInput();
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    // exchange.printDB();

    return 0;
}