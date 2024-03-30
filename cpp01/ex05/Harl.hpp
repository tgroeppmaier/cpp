#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
    void debug();
    void info();
    void warning();
    void error();

    struct ComplaintLevel {
        std::string level;
        void (Harl::*complaintFunc)(); // pointer to member function
    };

    static const ComplaintLevel complaintLevels[];

public:
    void complain(std::string level);
};

#endif