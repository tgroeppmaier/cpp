#include "ClapTrap.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;

// Default constructor
ClapTrap::ClapTrap() : m_name("Default"), m_hit_points(10), m_energy_points(10), m_attack_dmg(0) {
    cout << "Default constructor called on " << m_name << '\n';
}

// Parameterized constructor name
ClapTrap::ClapTrap(const string& name) : m_name(name), m_hit_points(10), m_energy_points(10), m_attack_dmg(0) {
    cout << "Parameterized constructor called on " << this->m_name << '\n';
}
// Parameterized constructor
ClapTrap::ClapTrap(const string& name, uint hp, uint ep, uint ad) : m_name(name), m_hit_points(hp), m_energy_points(ep), m_attack_dmg(ad) {
    cout << "Parameterized constructor called on " << this->m_name << '\n';
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) 
    : m_name(other.m_name), m_hit_points(other.m_hit_points), 
      m_energy_points(other.m_energy_points), m_attack_dmg(other.m_attack_dmg) {
        cout << "Copy constructor called and values copied from ClapTrap named " << other.m_name << '\n';      }

// Destructor
ClapTrap::~ClapTrap() {
    cout << "Destructor called on "<< this->m_name << '\n';

}

// Assignment operator overload
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        m_name = other.m_name;
        m_hit_points = other.m_hit_points;
        m_energy_points = other.m_energy_points;
        m_attack_dmg = other.m_attack_dmg;
    }
    return *this;
}

void ClapTrap::attack(const string& target){
    cout << m_name << " attacks " << target << " for " << 

}
