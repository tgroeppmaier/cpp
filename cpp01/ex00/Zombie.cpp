#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::Zombie() : name_("Zombie") {}

Zombie::~Zombie() {}

void Zombie::announce(void) {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}