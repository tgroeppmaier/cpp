#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <map>

using std::string;
using std::cout;
using std::map;

#define DB_PATH "data.csv"

class BitcoinExchange {
    private:
        string m_db_path;
        map<string, float> m_db_data;
        string m_input_data;

        bool isValidLine(const std::string& line);
        bool isValidDate(const std::string& line);

    public:
        BitcoinExchange(const string& db_path);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& other);

        void initializeDB();
        void readInput(const string& input_path);
        void processInput();

        void printDB();
};

#endif