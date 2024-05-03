#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), m_name("Default_Diamond") {
	cout << "DiamondTrap default constructor called\n";
	// m_hit_points = FragTrap::getHitPoints();
	// m_energy_points = ScavTrap::getEnergyPoints();
	// m_attack_dmg = FragTrap::getAttackDamage();
}