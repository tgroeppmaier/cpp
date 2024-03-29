#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name, Weapon* weapon) : name_(name), weapon_(weapon) {}  // No change needed

void HumanB::setWeapon(Weapon& weapon) {
    weapon_ = &weapon;
}

void HumanB::attack() const {
    if (weapon_) {
        std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
    } else {
        std::cout << name_ << " has no weapon to attack with" << std::endl;
    }
}