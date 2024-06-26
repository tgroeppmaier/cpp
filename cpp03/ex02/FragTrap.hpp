#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    protected:

    public:
        FragTrap();
        FragTrap(const string& name);
        FragTrap(const FragTrap& other);
        ~FragTrap();

        FragTrap& operator=(const FragTrap& other);
        void attack(const string& target);
        void highFivesGuys();
};

#endif