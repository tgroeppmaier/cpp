#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>  // For std::fixed and std::setprecision
#include <cstdlib> // For atof
#include <cctype> // Include this for std::isdigit

// BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& db_path) : m_db_path(db_path), m_db_data(), m_input_data() {}

BitcoinExchange::BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::initializeDB() {
    std::ifstream dbFile(m_db_path.c_str());
    if (!dbFile) {
        throw std::runtime_error("Failed to open database file at " + m_db_path);
    }

   std::string line;
   std::getline(dbFile, line); // read and discard first line
    while (std::getline(dbFile, line)) {
        std::istringstream lineStream(line);
        string dateStr, rateStr;
        if (std::getline(lineStream, dateStr, ',') && std::getline(lineStream, rateStr)) {
            float rate;
            std::istringstream(rateStr) >> rate;
            m_db_data[dateStr] = rate;
        }
    }
}

// 0 1 2 3 4 5 6 7 8 9
// Y Y Y Y - M M - D D
// input in format "yyyy-mm-dd | float 0-1000"

bool BitcoinExchange::isValidLine(const std::string& line) {
    // Check format "yyyy-mm-dd | "
    if (line.length() < 13 || line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
            cout << "Error: bad input => " << line << std::endl;
            return false;
        }

    // Check if year, month, and day are digits
    for (size_t i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue; // Skip '-' characters
        if (!std::isdigit(line[i])) {
            cout << "Error: bad input => " << line << std::endl;
            return false;
        }
    }

    // Extract and validate the float part
    std::string floatPart = line.substr(13);
    char* end;
    double value = std::strtod(floatPart.c_str(), &end);

    // Check if conversion consumed the entire string and if value is in range
    if (*end != '\0') {
        cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (value < 0.0) {
        cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000.0) {
        cout << "Error: too large number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::readInput(const std::string& input_path) {
    // Check for directory traversal attempts
    if (input_path.find("..") != std::string::npos || input_path.find('/') != std::string::npos) {
        throw std::runtime_error("Access to the specified file path is not allowed.");
    }

    std::ifstream inputFile(input_path.c_str());
    if (!inputFile) {
        throw std::runtime_error("Failed to open input file at " + input_path);
    }

    // Read the entire file into m_input_data
    m_input_data.assign((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());
}

void BitcoinExchange::processInput() {
    std::istringstream iss(m_input_data);
    std::string line;
    double amount;
    char *end;

    while (std::getline(iss, line)) {
        if (!isValidLine(line)) {
            continue;
        }
        std::string part = line.substr(0, 10); // Assuming 'part' is the date in 'yyyy-mm-dd' format

        std::map<std::string, float>::iterator it = m_db_data.lower_bound(part);
        if (it == m_db_data.end()) {
            // No element is greater than or equal to 'part', hence no younger date found
            std::cout << "No younger date found for " << part << std::endl;
        } else {
            // Found a date that is not younger than 'part'
            // Directly use 'it' without decrementing, as 'lower_bound' already gives us the closest non-younger date
            amount = strtod(line.c_str() + 13, &end);
            std::cout << it->first << " => " << amount << " = " << it->second * amount << std::endl;
        }
    }
}



void BitcoinExchange::printDB() {
    std::map<std::string, float>::iterator it = m_db_data.begin();
    for (; it != m_db_data.end(); ++it) {
        std::cout << it->first << " : " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}



