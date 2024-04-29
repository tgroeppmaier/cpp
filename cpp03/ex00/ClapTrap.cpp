#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : m_name(""), m_hit_points(0), m_energy_points(0), m_attack_dmg(0) {}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) 
    : m_name(other.m_name), m_hit_points(other.m_hit_points), 
      m_energy_points(other.m_energy_points), m_attack_dmg(other.m_attack_dmg) {}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        m_name = other.m_name;
        m_hit_points = other.m_hit_points;
        m_energy_points = other.m_energy_points;
        m_attack_dmg = other.m_attack_dmg;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {}