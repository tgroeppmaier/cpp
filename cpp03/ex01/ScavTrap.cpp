#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

using std::string;
using std::cout;

ScavTrap::ScavTrap()
    : ClapTrap("Default_Scav", 100, 50, 20){
    cout << "Default ScavTrap constructor called on " << getName() << '\n';
}

ScavTrap::ScavTrap(const string name)
    : ClapTrap(name, 100, 50, 20){
    cout << "Named ScavTrap constructor called on " << getName() << '\n';
}

ScavTrap::~ScavTrap(){
    cout << "ScavTrap destructor called on "<< this->m_name << '\n';
}