#include "ClapTrap.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;

// Default constructor
ClapTrap::ClapTrap() 
    : m_name("Default"), m_hit_points(10), m_energy_points(10), m_attack_dmg(0) {
    cout << "Default ClapTrap constructor called on " << m_name << '\n';
}

// Parameterized constructor name
ClapTrap::ClapTrap(const string& name) 
    : m_name(name), m_hit_points(10), m_energy_points(10), m_attack_dmg(0) {
    cout << "Parameterized constructor called on " << m_name << '\n';
}

// Parameterized constructor
ClapTrap::ClapTrap(const string& name, unsigned int hp, unsigned int ep, unsigned int ad) 
    : m_name(name), m_hit_points(hp), m_energy_points(ep), m_attack_dmg(ad) {
    cout << "Parameterized constructor called on " << m_name << '\n';

    if (hp > MAX_HP) {
        m_hit_points = MAX_HP;
        cout << "hp value out of bounds. Setting to MAX_HP.\n";
    }
    if (ep > MAX_EP) {
        m_energy_points = MAX_EP;
        cout << "ep value out of bounds. Setting to MAX_EP.\n";
    }
    if (ad > MAX_AD) {
        m_attack_dmg = MAX_AD;
        cout << "ad value out of bounds. Setting to MAX_AD.\n";
    }
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
    if(m_energy_points > 0 && m_hit_points > 0)
    {
        cout << m_name << " attacks " << target << " for " << m_attack_dmg << "\n";
        m_energy_points -= 1;
        cout << m_name << " has now " << m_energy_points << " energy left " << '\n';
    }
    else
        cout << m_name << " cannot attack, it has not enough hp or energy points\n";
}

void ClapTrap::takeDamage(unsigned int amount){
    if(m_hit_points < amount){
        m_hit_points = 0;
        cout << m_name << " suffers " << amount << " damage and its health is now " << m_hit_points << '\n';
    }
    else{
        m_hit_points -= amount;
        cout << m_name << " suffers " << amount << " damage and its health is now " << m_hit_points << '\n';
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if(m_energy_points > 0 && m_hit_points > 0){
        m_hit_points += amount;
        if(m_hit_points > 100)
            m_hit_points = 100;
        m_energy_points -= 1; 
        cout << m_name << " repairs itself for " << amount << " hp its health is now " << m_hit_points << '\n';
        cout << m_name << " has now " << m_energy_points << " energy left " << '\n';
    }
    else
        cout << m_name << " cannot repair, it has not enough hp or energy points\n";
}

void ClapTrap::printValues()
{
    cout << "Name: " << m_name << '\n';
    cout << "HP: " << m_hit_points << '\n';
    cout << "Energy: " << m_energy_points << '\n';
    cout << "AD: " << m_attack_dmg << '\n';
}

// getters

string ClapTrap::getName(){
    return m_name;
}

unsigned int ClapTrap::getHP(){
    return m_hit_points;
}

unsigned int ClapTrap::getEP(){
    return m_energy_points;
}

unsigned int ClapTrap::getAD(){
    return m_attack_dmg;
}

void ClapTrap::setName(string name){
    m_name = name;
}
