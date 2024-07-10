#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <map>

#define DB_PATH "data.csv"

class BitcoinExchange {
    private:
        std::string m_db_path;
        std::map<std::string, float> m_db_data;
        std::string m_input_data;

        bool isValidLine(const std::string& line);
        bool isValidDate(const std::string& line);

    public:
        BitcoinExchange(const std::string& db_path);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& other);

        void initializeDB();
        void readInput(const std::string& input_path);
        void processInput();

        void printDB();
};

#endif