#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
using std::string;

class ClapTrap {
private:
    string m_name;
    int m_hit_points;
    int m_energy_points;
    int m_attack_dmg;

public:
    // Default constructor
    ClapTrap();

    // Copy constructor
    ClapTrap(const ClapTrap& other);

    // Assignment operator
    ClapTrap& operator=(const ClapTrap& other);

    // Destructor
    ~ClapTrap();

    void attack(const string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif