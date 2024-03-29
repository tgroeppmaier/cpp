#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void) {
    Zombie *z1 = newZombie("Homer");
    z1->announce();
    Zombie *z2 = newZombie("Lenny");
    z2->announce();
    randomChump("Rando");

    delete z1;
    delete z2;
    return 0;
}