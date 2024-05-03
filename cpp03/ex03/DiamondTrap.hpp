#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

using std::string;

class DiamondTrap : public FragTrap, public ScavTrap{
    private:
        string m_name;

    public:
        DiamondTrap();
        DiamondTrap(const string& name);
        ~DiamondTrap();
};



#endif