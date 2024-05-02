#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : private ClapTrap {
    private:
        bool m_guard_mode;

    public:
        ScavTrap();
        ScavTrap(const string name);
        ~ScavTrap();

    void attack(const string& target);
    void guardGate();
};

#endif