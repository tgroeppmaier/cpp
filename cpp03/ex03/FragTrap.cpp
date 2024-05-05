#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

FragTrap::FragTrap()
    : ClapTrap("Default_Frag", 100, 100, 30){
    cout << "Default FragTrap constructor called\n";
}

FragTrap::FragTrap(const string& name)
    : ClapTrap(name, 100, 100, 30){
    cout << "Parameterized FragTrap constructor called on " << name << '\n';
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other.m_name, other.m_hit_points, other.m_energy_points, other.m_attack_dmg){
    cout << "FragTrap copy constructor called on " << m_name << '\n';
    }

FragTrap::~FragTrap(){
    cout << "FragTrap destructor called on "<< m_name << '\n';
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::attack(const string& target){
    if(m_energy_points > 0 && m_hit_points > 0)
    {
        cout << "FragTrap " << m_name << " attacks " << target << " for " << m_attack_dmg << "\n";
        m_energy_points -= 1;
        cout << m_name << " has now " << m_energy_points << " energy left " << '\n';
    }
    else
        cout << "FragTrap " << m_name << " cannot attack, it has not enough hp or energy points\n";
}

void FragTrap::highFivesGuys(){
    cout << "FragTrap " << m_name << " gives you a high five\n";
}
