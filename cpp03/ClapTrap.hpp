#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
    std::string m_name;
    int m_hit_points;
    int m_energy_points;
    int m_attack_dmg;

public:
    ClapTrap() 

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif