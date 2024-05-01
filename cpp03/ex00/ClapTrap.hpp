#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
using std::string;

// using std::cout;

class ClapTrap {
private:
    string m_name;
    unsigned int m_hit_points;
    unsigned int m_energy_points;
    unsigned int m_attack_dmg;


public:
    static const unsigned int MAX_HP = 100;
    static const unsigned int MAX_EP = 100;
    static const unsigned int MAX_AD = 100;

    // Default constructor
    ClapTrap();
    
    // Parameterized constructor name
    ClapTrap(const string& name);

    // Parameterized constructor
    ClapTrap(const string& name, unsigned int hp, unsigned int ep, unsigned int ad);

    // Copy constructor
    ClapTrap(const ClapTrap& other);

    // Assignment operator
    ClapTrap& operator=(const ClapTrap& other);

    // Destructor
    ~ClapTrap();

    void attack(const string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void printValues();

};

#endif