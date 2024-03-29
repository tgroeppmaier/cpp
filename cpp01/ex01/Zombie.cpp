#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::Zombie() : name_("Zombie") {}

Zombie::~Zombie(){
	std::cout << name_ << " died" << std::endl;
}

void Zombie::announce(void) {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    name_ = name;
}