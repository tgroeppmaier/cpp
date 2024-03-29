#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name_;
    Weapon* weapon_; // we use pointer because reference must be initialised

public:
    HumanB(const std::string& name, Weapon* weapon = NULL);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif