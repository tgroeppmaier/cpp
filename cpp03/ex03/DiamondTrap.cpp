#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;

DiamondTrap::DiamondTrap() 
	: ClapTrap(), 
	  FragTrap(), 
	  ScavTrap(), 
	  m_name("Default_Diamond") 
{
	cout << "DiamondTrap default constructor called\n";
	m_hit_points = FragTrap::getHP();
	m_energy_points = ScavTrap::getEP();
	m_attack_dmg = FragTrap::getAD();
}

DiamondTrap::DiamondTrap(const string& name)
	: ClapTrap(name + "_clap_name"),
	  FragTrap(),
	  ScavTrap(),
	  m_name(name)
{
	cout << "DiamondTrap constructor called on\n" << m_name << '\n';
	m_hit_points = FragTrap::getHP();
	m_energy_points = ScavTrap::getEP();
	m_attack_dmg = FragTrap::getAD();
}

DiamondTrap::~DiamondTrap(){
	cout << "DiamondTrap destructor called on\n" << m_name << '\n';
}

&DiamondTrap



