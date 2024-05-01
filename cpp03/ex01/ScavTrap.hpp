#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:
        // string m_name_scav;

    public:
        ScavTrap();
        ScavTrap(const string name);
        ~ScavTrap();
};

#endif