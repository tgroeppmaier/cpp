#include "Harl.hpp"
#include <iostream>

void Harl::debug() { std::cout << "Debug: Something might be going wrong.\n"; }
void Harl::info() { std::cout << "Info: Everything is going fine.\n"; }
void Harl::warning() { std::cout << "Warning: Something definitely is going wrong.\n"; }
void Harl::error() { std::cout << "Error: Something went wrong.\n"; }

const Harl::ComplaintLevel Harl::complaintLevels[] = {
    {"debug", &Harl::debug},
    {"info", &Harl::info},
    {"warning", &Harl::warning},
    {"error", &Harl::error}
};

void Harl::complain(std::string level) {
    for (size_t i = 0; i < sizeof(complaintLevels) / sizeof(complaintLevels[0]); i++) {
        if (complaintLevels[i].level == level) {
            (this->*complaintLevels[i].complaintFunc)();
            return;
        }
    }
    std::cout << "Invalid complaint level: " << level << "\n";
}