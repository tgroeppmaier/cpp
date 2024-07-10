#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision
#include <cstdlib> // For atof
#include <cctype>  // Include this for std::isdigit

BitcoinExchange::BitcoinExchange(const std::string &db_path) : m_db_path(db_path), m_db_data(), m_input_data() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : m_db_path(other.m_db_path), m_db_data(other.m_db_data), m_input_data(other.m_input_data) {}

BitcoinExchange::BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        m_db_path = other.m_db_path;
        m_db_data = other.m_db_data;
        m_input_data = other.m_input_data;
    }
    return *this;
}

void BitcoinExchange::initializeDB()
{
    std::ifstream dbInputStream(m_db_path.c_str());
    if (!dbInputStream) {
        throw std::runtime_error("Failed to open database file at " + m_db_path);
    }

    std::string line;
    std::getline(dbInputStream, line); // read and discard first line
    while (std::getline(dbInputStream, line))
    {
        std::istringstream lineStream(line);
        std::string dateStr, rateStr;
        if (std::getline(lineStream, dateStr, ',') && std::getline(lineStream, rateStr))
        {
            float rate;
            std::istringstream(rateStr) >> rate; // create a tmp ss object and then extract it into rate
            m_db_data[dateStr] = rate;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string &line)
{
    std::string date = line.substr(0, 10);

    int year, month, day;
    std::istringstream dateStream(date.substr(0, 4) + " " + date.substr(5, 2) + " " + date.substr(8, 2)); // start position + length
    dateStream >> year >> month >> day;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month])
    {
        std::cout << "Error: Date out of range => " << date << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidLine(const std::string &line)
{
    // Check format "yyyy-mm-dd | "
    if (line.length() < 13 || line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    // Check if year, month, and day are digits
    for (size_t i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue; // Skip '-' characters
        if (!std::isdigit(line[i]))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            return false;
        }
    }

    // Extract and validate the float part
    std::string floatPart = line.substr(13);
    char *end;
    double value = std::strtod(floatPart.c_str(), &end);

    bool isValid = true;
    if (*end != '\0') {
        std::cout << "Error: bad input => " << line << std::endl;
        isValid = false;
    } 
    else if (value < 0.0) {
        std::cout << "Error: not a positive number." << std::endl;
        isValid = false;
    } 
    else if (value > 1000.0) {
        std::cout << "Error: too large number." << std::endl;
        isValid = false;
    }
    return isValid;
}

void BitcoinExchange::readInput(const std::string &input_path)
{
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

void BitcoinExchange::processInput()
{
    std::istringstream inputStream(m_input_data);
    std::string line;
    double amount;
    char *end;

    while (std::getline(inputStream, line))
    {
        if (!isValidLine(line) || !isValidDate(line)) {
            continue;
        }
        std::string part = line.substr(0, 10);

        std::map<std::string, float>::iterator it = m_db_data.upper_bound(part); // find matching date
        if (it == m_db_data.begin()) {
            std::cout << "All dates in DB are younger than " << part << std::endl;
        }
        else { // if date could not be found, take next higher and decrement 1
            --it;
            amount = strtod(line.c_str() + 13, &end);
            std::cout << it->first << " => " << amount << " = " << it->second * amount << std::endl;
        }
    }
}

void BitcoinExchange::printDB()
{
    std::map<std::string, float>::iterator it = m_db_data.begin();
    for (; it != m_db_data.end(); ++it) {
        std::cout << it->first << " : " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}
