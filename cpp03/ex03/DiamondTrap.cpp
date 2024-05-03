#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called\n";
	this->_hitPoints = FragTrap::_maxHitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = ScavTrap::_maxEnergyPoints;
	this->_maxEnergyPoints = ScavTrap::_maxEnergyPoints;
	this->_attackDamage = FragTrap::_maxAttackDamage;
	this->_maxAttackDamage = FragTrap::_maxAttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(const FragTrap& fragTrap, const ScavTrap& scavTrap)
	: FragTrap(fragTrap), ScavTrap(scavTrap), m_name(fragTrap.getName() + "_clap_name") {
	cout << "DiamondTrap constructor called\n";
}