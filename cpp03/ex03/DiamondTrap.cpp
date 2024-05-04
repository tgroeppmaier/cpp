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
	  FragTrap(name),
	  ScavTrap(name),
	  m_name(name)
{
	cout << "DiamondTrap constructor called\n";
	m_hit_points = FragTrap::getHP();
	m_energy_points = ScavTrap::getEP();
	m_attack_dmg = FragTrap::getAD();
}

DiamondTrap::~DiamondTrap(){
	cout << "DiamondTrap destructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), 
	  FragTrap(other), 
	  ScavTrap(other), 
	  m_name(other.m_name) 
{
	cout << "DiamondTrap copy constructor called\n";
	m_hit_points = other.m_hit_points;
	m_energy_points = other.m_energy_points;
	m_attack_dmg = other.m_attack_dmg;
}

void DiamondTrap::whoAmI() {
	cout << "My name is " << m_name << ", and my ClapTrap name is " << ClapTrap::getName() << '\n';
}

