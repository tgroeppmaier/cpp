#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

ScavTrap::ScavTrap()
    : ClapTrap("Default_Scav", 100, 50, 20), m_guard_mode(false){
    cout << "Default ScavTrap constructor called on " << getName() << '\n';
}

ScavTrap::ScavTrap(const string& name)
    : ClapTrap(name, 100, 50, 20), m_guard_mode(false){
    cout << "Parameterized ScavTrap constructor called on " << getName() << '\n';
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other.m_name, other.m_hit_points, other.m_energy_points, other.m_attack_dmg){
    cout << "ScavTrap copy constructor called on " << getName() << '\n';
    }

ScavTrap::~ScavTrap(){
    cout << "ScavTrap destructor called on "<< this->m_name << '\n';
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    if(this != &other){
        m_name = other.m_name;
        m_hit_points = other.m_hit_points;
        m_energy_points = other.m_energy_points;
        m_attack_dmg = other.m_attack_dmg;
    }
    return *this;
}

void ScavTrap::attack(const string& target){
    if(m_energy_points > 0 && m_hit_points > 0)
    {
        cout << "ScavTrap " << m_name << " attacks " << target << " for " << m_attack_dmg << "\n";
        m_energy_points -= 1;
        cout << m_name << " has now " << m_energy_points << " energy left " << '\n';
    }
    else
        cout << "ScavTrap " << m_name << " cannot attack, it has not enough hp or energy points\n";
}

void ScavTrap::guardGate() {
    m_guard_mode = !m_guard_mode;
    if (m_guard_mode) {
        cout << "ScavTrap " << m_name << " has entered Guard Mode.\n";
    } else {
        cout << "ScavTrap " << m_name << " has exited Guard Mode.\n";
    }
}