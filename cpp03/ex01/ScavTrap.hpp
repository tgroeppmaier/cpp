#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    protected:
        bool m_guard_mode;

    public:
        ScavTrap();
        ScavTrap(const string& name);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);
        void attack(const string& target);
        void guardGate();
};

#endif