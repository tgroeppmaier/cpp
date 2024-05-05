#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;

DiamondTrap::DiamondTrap() 
	: ClapTrap("Default_clap_name"),
	  FragTrap(), 
	  ScavTrap(), 
	  m_name("Default_Diamond") 
{
	cout << "DiamondTrap default constructor called\n";
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_dmg = 30;
}

DiamondTrap::DiamondTrap(const string& name)
	: ClapTrap(name + "_clap_name"),
	  FragTrap(name),
	  ScavTrap(name),
	  m_name(name)
{
	cout << "DiamondTrap constructor called\n";
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_dmg = 30;
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
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
	if(this != &other){
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		m_name = other.m_name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	cout << "My name is " << m_name << ", and my ClapTrap name is " << ClapTrap::getName() << '\n';
}

