#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : private ClapTrap {
    private:

    public:
        FragTrap();
        FragTrap(const string name);
        ~FragTrap();

    void attack(const string& target);
    void highFivesGuys();
};

#endif